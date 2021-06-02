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

		std::vector<Message> list = message.m_channel->GetMessages(10);
		message.m_channel->DeleteMessageBulk(list);
	}

};

int main() {
	Bot b;
	b.Start("");

	std::cin.get();
	std::cin.get();
	std::cin.get();

	return 0;
}
