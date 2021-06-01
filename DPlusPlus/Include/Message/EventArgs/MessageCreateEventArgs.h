#pragma once

#include "nlohmann/json.hpp"

using nJson = nlohmann::json;

class Message;
class Channel;
class User;

class MessageCreateEventArgs {

public:
	MessageCreateEventArgs(const nJson &json);

public:
	Message *message;
	Channel *channel;
	User *user;

};