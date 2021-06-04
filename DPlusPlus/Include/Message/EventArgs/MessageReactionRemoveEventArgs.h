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

class MessageReactionRemoveEventArgs {

public:
	MessageReactionRemoveEventArgs(const nJson &json);
	~MessageReactionRemoveEventArgs();

public:
	Message *m_Message;
	Channel *m_Channel;
	Member *m_Member;
	Guild *m_Guild;
	Emoji *m_Emoji;

};
