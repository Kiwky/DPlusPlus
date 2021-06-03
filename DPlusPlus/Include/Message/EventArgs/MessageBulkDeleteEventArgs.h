#pragma once

#include <vector>

#include "nlohmann/json.hpp"

#include "Snowflake.h"
#include "Globals.h"

using nJson = nlohmann::json;

class Channel;
class Guild;

class MessageBulkDeleteEventArgs {

public:
	MessageBulkDeleteEventArgs(const nJson &json);
	~MessageBulkDeleteEventArgs();

public:
	std::vector<Snowflake> m_ids;
	Channel *m_channel;
	Guild *m_guild;

};

