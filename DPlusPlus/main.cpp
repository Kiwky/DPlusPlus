#include <iostream>
#include <string>

#include "Discord.h"

class Bot: public Discord {

};

int main() {
	std::cout << Discord::GetToken();
	Bot b;
	b.Start("TOKEN");

	int x;
	std::cin >> x;

	return 0;
}
