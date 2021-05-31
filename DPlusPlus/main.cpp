#include <iostream>
#include <string>

#include "Discord.h"

class Bot: public Discord {

public:
	virtual void OnMessageCreated(const Message &message) override {
		std::cout << message.m_content;
	}

};

int main() {
	Bot b;
	b.Start("TOKEN");

	std::cin.get();
	std::cin.get();
	std::cin.get();

	return 0;
}
