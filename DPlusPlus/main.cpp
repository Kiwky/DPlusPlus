﻿#include <iostream>
#include <string>
#include <thread>

#include "Token.h"
#include "Discord.h"
#include "Entities/Channel/Channel.h"
#include "Entities/Message/Message.h"

class Bot: public Discord {

public:
	virtual void OnReady(const ReadyEventArgs &ready) {
		std::cout << ready.m_GatewayVersion << " " << ready.m_SessionId << "\n";
	}

	virtual void OnMessageCreated(const MessageCreateEventArgs &message) override {
		std::cout << message.m_Message->m_Content << "\n";
		std::cout << message.m_Channel->m_Name << "\n";
	}

	virtual void OnMessageDeleted(const MessageDeleteEventArgs &message) override {
		std::cout << message.m_Id << "\n";
		std::cout << message.m_Channel->m_Name << "\n";

		std::vector<Message> list = message.m_Channel->GetMessages(2);
		message.m_Channel->DeleteMessageBulk(list);
	}

	virtual void OnMessageUpdate(const MessageUpdateEventArgs &message) override {
		std::cout << message.m_Message->m_Content << "\n";
		std::cout << message.m_Member->m_Nick << "\n";
	}

	virtual void OnMessageDeletedBulk(const MessageBulkDeleteEventArgs &message) override {
		for(int i = 0; i < message.m_Ids.size(); i++) {
			std::cout << message.m_Ids[i] << "\n";
		}
		std::cout << "Entities/Guild Name: " << message.m_Guild->m_Name << "\n";
		std::cout << "Channel Name: " << message.m_Channel->m_Name << "\n";
	}

	virtual void OnMessageReactionAdd(const MessageReactionAddEventArgs &message) override {
		std::cout << "Channel name: " << message.m_Channel->m_Name << "\n";
		std::cout << "Content: " << message.m_Message->m_Content << "\n";
		std::cout << "User: " << message.m_Member->m_User->m_Username << "\n";
	}

	virtual void OnMessageReactionRemoved(const MessageReactionRemoveEventArgs &message) override {
		std::cout << "Channel name: " << message.m_Channel->m_Name << "\n";
		std::cout << "Content: " << message.m_Message->m_Content << "\n";
		std::cout << "User: " << message.m_Member->m_User->m_Username << "\n";
	}

	virtual void OnMessageReactionRemoveEmoji(const MessageReactionRemoveEmojiEventArgs &message) {
		std::cout << message.m_Guild->m_Name << "\n";
	}
};

int main() {
	Bot b;
	b.Start(BOT_TOKEN);

	std::cin.get();
	std::cin.get();
	std::cin.get();

	return 0;
}
