#pragma once

#include "nlohmann/json.hpp"

#include "Snowflake.h"
#include "Globals.h"

using nJson = nlohmann::json;

class Message;
class Channel;
class Member;
class Guild;
class Emoji;

class MessageReactionAddEventArgs {

public:
	MessageReactionAddEventArgs(const nJson &json);
	~MessageReactionAddEventArgs();

public:
	Message *m_message;
	Channel *m_channel;
	Member *m_member;
	Guild *m_guild;
	Emoji *m_emoji;

};

