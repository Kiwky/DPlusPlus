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
	Message *m_Message;
	Channel *m_Channel;
	Member *m_Member;
	Guild *m_Guild;
	Emoji *m_Emoji;

};

