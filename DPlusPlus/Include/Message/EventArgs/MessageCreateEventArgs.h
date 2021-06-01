#pragma once

#include "nlohmann/json.hpp"

#include "Globals.h"

using nJson = nlohmann::json;

class Message;
class Channel;

class MessageCreateEventArgs {

public:
	MessageCreateEventArgs(const nJson &json);
	~MessageCreateEventArgs();

public:
	Message *m_message;
	Channel *m_channel;

};