#pragma once

#include <vector>

#include "nlohmann/json.hpp"

#include "Snowflake.h"
#include "Globals.h"

using nJson = nlohmann::json;

class Channel;
class Guild;
class Message;

class MessageReactionsClearEventArgs {

public:
	MessageReactionsClearEventArgs(const nJson &json);
	~MessageReactionsClearEventArgs();

public:
	Guild *m_Guild;
	Channel *m_Channel;
	Message *m_Message;

};

