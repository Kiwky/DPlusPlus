#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cpprest/ws_client.h>
#include <cpprest/http_client.h>

#include "nlohmann/json.hpp"

#include "Log.h"
#include "Globals.h"
#include "Library.h"

using namespace web;
using namespace web::http;
using namespace web::websockets::client;
using nJson = nlohmann::json;

enum class OP_Type {
	kDispatch				/**/ = 0,
	kHeartbeat				/**/ = 1,
	kIdentify				/**/ = 2,
	kStatusUpdate			/**/ = 3,
	kVoiceStateUpdate		/**/ = 4,
	kVoiceServerPing		/**/ = 5,
	kResume					/**/ = 6,
	kReconect				/**/ = 7,
	kRequestGuildMember		/**/ = 8,
	kInvalidSession			/**/ = 9,
	kHello					/**/ = 10,
	kHeartbeatAck			/**/ = 11
};

class Discord {

public:
	void Start(const std::string &token);
	void ModifyPresence(const std::string &name, const std::string &status = "online");

	static std::string &GetToken();
	static std::string GetOS();

public:
	// Sent when a message is created. 
	virtual void OnMessageCreated(const MessageCreateEventArgs &message);

	// Sent when a message is deleted. 
	virtual void OnMessageDeleted(const MessageDeleteEventArgs &message);

	// Sent when a message is updated. 
	virtual void OnMessageUpdate(const MessageUpdateEventArgs &message);

private:
	void ProcessBotIdentity();
	void ProcessBotHeartbeat();
	void ProcessBotResponse(websocket_incoming_message &message);

private:
	static std::string m_token;
	websocket_callback_client m_client;
	int m_lastSignal;
	int m_heartbeatInterval;
	bool m_isReady;
	std::string m_sessionId;
	std::thread *m_heartbeatThread;

};

