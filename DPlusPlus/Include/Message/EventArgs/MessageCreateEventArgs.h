#pragma once

#include "Globals.h"
#include "nlohmann/json.hpp"

using nJson = nlohmann::json;

class Message;
class Channel;
class User;

class MessageCreateEventArgs {

public:
	MessageCreateEventArgs(const nJson &json);
	~MessageCreateEventArgs();

public:
	Message *message;
	Channel *channel;
	User *user;

};