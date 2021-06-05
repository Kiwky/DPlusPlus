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
	// The ready event is dispatched when a client has completed the initial handshake with the gateway.
	virtual void OnReady(const ReadyEventArgs &ready);

	// Sent when a message is created. 
	virtual void OnMessageCreated(const MessageCreateEventArgs &message);

	// Sent when a message is deleted. 
	virtual void OnMessageDeleted(const MessageDeleteEventArgs &message);

	// Sent when a message is updated. 
	virtual void OnMessageUpdate(const MessageUpdateEventArgs &message);

	// Sent when multiple messages are deleted at once. 
	virtual void OnMessageDeletedBulk(const MessageBulkDeleteEventArgs &message);

	// Sent when a user adds a reaction to a message. 
	virtual void OnMessageReactionAdd(const MessageReactionAddEventArgs &message);

	// Sent when a user remove a reaction to a message. 
	virtual void OnMessageReactionRemoved(const MessageReactionRemoveEventArgs &message);

	// Sent when a user explicitly removes all reactions from a message. 
	virtual void OnMessageReactionClear(const MessageReactionsClearEventArgs &message);

	// Sent when a bot removes all instances of a given emoji from the reactions of a message.
	virtual void OnMessageReactionRemoveEmoji(const MessageReactionRemoveEmojiEventArgs &message);

private:
	void ProcessBotIdentity();
	void ProcessBotHeartbeat();
	void ProcessBotResponse(websocket_incoming_message &message);

private:
	static std::string m_Token;
	websocket_callback_client m_Client;
	int m_LastSignal;
	int m_HeartbeatInterval;
	bool m_IsReady;
	std::string m_SessionId;
	std::thread *m_HeartbeatThread;

};

