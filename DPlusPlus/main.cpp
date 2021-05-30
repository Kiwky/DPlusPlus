#include <iostream>
#include <string>

#include "Discord.h"

#include <cpprest/ws_client.h>
#include <cpprest/http_client.h>
using namespace std;
using namespace web::json;
using namespace web::http;
using namespace web::http::client;
using namespace utility;

class Bot: public Discord {

};

int main() {
	Bot b;
	b.Start("TOKEN");

	std::cin.get();
	std::cin.get();
	std::cin.get();

	return 0;
}
