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

			switch(hash_string(type.c_str())) {
				case hash_string("READY"):
				{
					break;
				}
				case hash_string("MESSAGE_CREATE"):
				{
					MessageCreateEventArgs message(data);

					// Call virtual function.
					OnMessageCreated(message);
					break;
				}
				case hash_string("MESSAGE_UPDATE"):
				{
					MessageDeleteEventArgs message(data);

					// Call virtual function.
					//OnMessageUpdate(message);
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

nJson Discord::API_Call(const std::string &url, method apiMethod, const std::string &jsonObject) {
	try {
		web::json::value jsonValue;
		web::http::client::http_client client(
			web::uri(utility::conversions::to_string_t(GLOBAL_API_URL))
		);
		std::string httpToken = "Bot " + Discord::GetToken();

		http_request req(apiMethod);
		req.set_request_uri(web::uri(utility::conversions::to_string_t(url)));
		req.headers().add(L"Authorization", httpToken.c_str());
		req.headers().add(L"User-Agent", L"DPlusPlus");
		req.headers().add(L"Content-Type", L"application/json");

		if((apiMethod != methods::GET) && (apiMethod != methods::HEAD))
			req.set_body(jsonObject);

		utility::string_t responseString;
		unsigned short code = 0;

		do {
			pplx::task<http_response> requestTask = client.request(req).then([](http_response response) {
				return response;
			});

			requestTask.wait();
			responseString = requestTask.get().extract_string().get();

			code = requestTask.get().status_code();
		} while(code == 429);

		nJson s = nJson::parse(responseString.begin(), responseString.end());
		return s;
	} catch(std::exception &e) {
		Log::Error("[API_Call error: " + std::string(e.what()));
	}
	return "";
}

