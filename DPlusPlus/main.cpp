#include <iostream>
#include <string>

#include "Discord.h"
#include "Channel/Channel.h"

class Bot: public Discord {

public:
	virtual void OnMessageCreated(const MessageCreateEventArgs &message) override {
		std::cout << message.m_message->m_content << "\n";
		std::cout << message.m_channel->m_name << "\n";
	}

	virtual void OnMessageDeleted(const MessageDeleteEventArgs &message) override {
		std::cout << message.m_id << "\n";
		std::cout << message.m_channel->m_name << "\n";
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
