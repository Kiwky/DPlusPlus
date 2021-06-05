#include "Discord.h"
#include "Intents.h"

std::string Discord::m_Token;

void Discord::Start(const std::string &token) {
	if(token.length() == 0) {
		Log::Error("No token has been set.");
		return;
	}

	m_Token = token;
	m_IsReady = false;
	m_LastSignal = 0;
	m_HeartbeatThread = nullptr;

	m_Client.set_message_handler([&](websocket_incoming_message msg) {
		try {
			ProcessBotResponse(msg);
		} catch(const std::exception &e) {
			Log::Error("Message handler error [CATCH]: " + std::string(e.what()));
		}
	});

	// Convert / Encode gateway string to uri.
	web::uri gUri = web::uri(utility::conversions::to_string_t(GLOBAL_GATEWAY_URL));
	m_Client.connect(gUri).then([&]() {
		ProcessBotIdentity();
	});

	m_Client.set_close_handler([&](websocket_close_status status,
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
	Intents intents;

	identity["op"] = OP_Type::kIdentify;
	identity["d"] = {
		{"token", GetToken()},
		{"intents", intents.GetIntents()},
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
	m_Client.send(msg);
}

void Discord::ProcessBotHeartbeat() {
	Log::Info("Bot heartbeat request.");

	websocket_outgoing_message msg;
	nJson hearbeat;

	hearbeat["op"] = OP_Type::kHeartbeat;
	hearbeat["d"] = m_LastSignal;

	msg.set_utf8_message(to_string(hearbeat));
	m_Client.send(msg);
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
			m_LastSignal = resultJson["s"];

			switch(DPlusPlus::hash_string(type.c_str())) {
				case DPlusPlus::hash_string("READY"):
				{
					ReadyEventArgs ready(data);

					// Call virtual function.
					OnReady(ready);
					break;
				}
				case DPlusPlus::hash_string("MESSAGE_CREATE"):
				{
					MessageCreateEventArgs message(data);

					// Call virtual function.
					OnMessageCreated(message);
					break;
				}
				case DPlusPlus::hash_string("MESSAGE_DELETE"):
				{
					MessageDeleteEventArgs message(data);

					// Call virtual function.
					OnMessageDeleted(message);
					break;
				}
				case DPlusPlus::hash_string("MESSAGE_UPDATE"):
				{
					MessageUpdateEventArgs message(data);

					// Call virtual function.
					OnMessageUpdate(message);
					break;
				}
				case hash_string("MESSAGE_DELETE_BULK"):
				{
					MessageBulkDeleteEventArgs message(data);

					// Call virtual function.
					OnMessageDeletedBulk(message);
					break;
				}
				case hash_string("MESSAGE_REACTION_ADD"):
				{
					MessageReactionAddEventArgs message(data);

					// Call virtual function.
					OnMessageReactionAdd(data);
					break;
				}
				case hash_string("MESSAGE_REACTION_REMOVE"):
				{
					MessageReactionRemoveEventArgs message(data);

					// Call virtual function.
					OnMessageReactionRemoved(message);
					break;
				}
				case hash_string("MESSAGE_REACTION_REMOVE_ALL"):
				{
					MessageReactionsClearEventArgs message(data);

					// Call virtual function.
					OnMessageReactionClear(message);
					break;
				}
				case hash_string("MESSAGE_REACTION_REMOVE_EMOJI"):
				{
					MessageReactionRemoveEmojiEventArgs message(data);

					// Call virtual function.
					OnMessageReactionRemoveEmoji(message);
					break;
				}
			}
			break;
		}
		case (int)OP_Type::kHello:
		{
			m_HeartbeatInterval = data["heartbeat_interval"];
			m_IsReady = true;

			if(m_HeartbeatThread != nullptr) {
				delete m_HeartbeatThread;
				m_HeartbeatThread = nullptr;
			}

			m_HeartbeatThread = new std::thread([&]() {
				while(true) {
					try {
						std::this_thread::sleep_for(std::chrono::milliseconds(m_HeartbeatInterval));
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
	return m_Token;
}

std::string Discord::GetOS() {
#ifdef _WIN32
	return "Windows";
#else
	return "Linux";
#endif
}