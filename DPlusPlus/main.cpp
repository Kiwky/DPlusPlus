#include <iostream>
#include <string>
#include <thread>

#include "Discord.h"
#include "Channel/Channel.h"
#include "Message/Message.h"

class Bot: public Discord {

public:
	virtual void OnMessageCreated(const MessageCreateEventArgs &message) override {
		std::cout << message.m_message->m_content << "\n";
		std::cout << message.m_channel->m_name << "\n";
	}

	virtual void OnMessageDeleted(const MessageDeleteEventArgs &message) override {
		std::cout << message.m_id << "\n";
		std::cout << message.m_channel->m_name << "\n";

		std::vector<Message> list = message.m_channel->GetMessages(2);
		message.m_channel->DeleteMessageBulk(list);
	}

	virtual void OnMessageUpdate(const MessageUpdateEventArgs &message) override {
		std::cout << message.m_message->m_content << "\n";
		std::cout << message.m_member->m_nick << "\n";
	}

	virtual void OnMessageDeletedBulk(const MessageBulkDeleteEventArgs &message) override {
		for(int i = 0; i < message.m_ids.size(); i++) {
			std::cout << message.m_ids[i] << "\n";
		}
		std::cout << "Guild Name: " << message.m_guild->m_name << "\n";
		std::cout << "Channel Name: " << message.m_channel->m_name << "\n";
	}

	virtual void OnMessageReactionAdd(const MessageReactionAddEventArgs &message) override {
		std::cout << "Channel name: " << message.m_channel->m_name << "\n";
		std::cout << "Content: " << message.m_message->m_content << "\n";
		std::cout << "User: " << message.m_member->m_user->m_username << "\n";
	}
};

int main() {
	Bot b;
	b.Start("Nzk1NzU1ODUxOTgxMzg5ODY0.X_N_Yw.qhXHjL00zHHUBYlToAO366uLDXo");

	std::cin.get();
	std::cin.get();
	std::cin.get();

	return 0;
}
