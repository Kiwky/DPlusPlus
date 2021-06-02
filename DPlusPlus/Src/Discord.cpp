#include "Discord.h"

std::string Discord::m_token;

void Discord::Start(const std::string &token) {
	if(token.length() == 0) {
		Log::Error("No token has been set.");
		return;
	}

	m_token = token;
	m_isReady = false;
	m_lastSignal = 0;
	m_heartbeatThread = nullptr;

	m_client.set_message_handler([&](websocket_incoming_message msg) {
		try {
			ProcessBotResponse(msg);
		} catch(const std::exception &e) {
			Log::Error("Message handler error [CATCH]: " + std::string(e.what()));
		}
	});

	// Convert / Encode gateway string to uri.
	web::uri gUri = web::uri(utility::conversions::to_string_t(GLOBAL_GATEWAY_URL));
	m_client.connect(gUri).then([&]() {
		ProcessBotIdentity();
	});

	m_client.set_close_handler([&](websocket_close_status status,
								   const utility::string_t &reason,
								   const std::error_code &code) {
		std::wcout << reason << "\n";
		std::cout << "Bot closed with error code: " << code.value() << "\n";
	});
}

void Discord::ProcessBotIdentity() {
	Log::Info("Process bot identity.");

	websocket_outgoing_message msg;
	nJson identity;

	identity["op"] = OP_Type::kIdentify;
	identity["d"] = {
		{"token", GetToken()},
		{"intents", 513},
		{"properties", {
			{"$os", GetOS()},
			{"$browser", "DPlusPlus"},
			{"$device", "DPlusPlus"},
		}},
		{"compress", false},
		{"large_threshold", 250}
	};

	// Convert 'identity' object (json object) to string and send it to server.
	msg.set_utf8_message(to_string(identity));
	m_client.send(msg);
}

void Discord::ProcessBotHeartbeat() {
	Log::Info("Bot heartbeat request.");

	websocket_outgoing_message msg;
	nJson hearbeat;

	hearbeat["op"] = OP_Type::kHeartbeat;
	hearbeat["d"] = m_lastSignal;

	msg.set_utf8_message(to_string(hearbeat));
	m_client.send(msg);
}

void Discord::ProcessBotResponse(websocket_incoming_message &message) {
	std::string result = message.extract_string().get();
	nJson resultJson = nJson::parse(result);

	int op = resultJson["op"];
	const nJson data = resultJson["d"];

	switch(op) {
		case (int)OP_Type::kDispatch:
		{
			const std::string type = resultJson["t"];
			m_lastSignal = resultJson["s"];

			switch(DPlusPlus::hash_string(type.c_str())) {
				case DPlusPlus::hash_string("READY"):
				{
					break;
				}
				case DPlusPlus::hash_string("MESSAGE_CREATE"):
				{
					MessageCreateEventArgs message(data);

					//Call virtual function.
					OnMessageCreated(message);
					break;
				}
				case DPlusPlus::hash_string("MESSAGE_DELETE"):
				{
					MessageDeleteEventArgs message(data);

					//Call virtual function.
					OnMessageDeleted(message);
					break;
				}
			}
			break;
		}
		case (int)OP_Type::kHello:
		{
			m_heartbeatInterval = data["heartbeat_interval"];
			m_isReady = true;

			if(m_heartbeatThread != nullptr) {
				delete m_heartbeatThread;
				m_heartbeatThread = nullptr;
			}

			m_heartbeatThread = new std::thread([&]() {
				while(true) {
					try {
						std::this_thread::sleep_for(std::chrono::milliseconds(m_heartbeatInterval));
						ProcessBotHeartbeat();
					} catch(const std::exception &e) {
						Log::Error("Heartbeat thread error: " + (std::string)e.what());
					}
				}
			});

			break;
		}
	}
}

std::string &Discord::GetToken() {
	return m_token;
}

std::string Discord::GetOS() {
#ifdef _WIN32
	return "Windows";
#else
	return "Linux";
#endif
}