#pragma once

#include "nlohmann/json.hpp"

#include "Snowflake.h"
#include "Globals.h"

using nJson = nlohmann::json;

class Channel;
class Guild;

class MessageDeleteEventArgs {

public:
	MessageDeleteEventArgs(const nJson &json);
	~MessageDeleteEventArgs();

public:
	Snowflake m_id;
	Channel *m_channel;
	Guild *m_guild;

};

