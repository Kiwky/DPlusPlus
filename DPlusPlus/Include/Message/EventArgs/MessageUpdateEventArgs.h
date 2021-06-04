#pragma once

#include "nlohmann/json.hpp"

#include "Snowflake.h"
#include "Globals.h"

using nJson = nlohmann::json;

class Message;
class Channel;
class Guild;
class Member;

class MessageUpdateEventArgs {

public:
	MessageUpdateEventArgs(const nJson &json);
	~MessageUpdateEventArgs();

public:
	Message *m_Message;
	Channel *m_Channel;
	Guild *m_Guild;
	Member *m_Member;

};

