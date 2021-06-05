#include "nlohmann/json.hpp"

#include "Snowflake.h"
#include "Globals.h"

using nJson = nlohmann::json;

class Guild;
class Channel;
class Message;
class Emoji;

class MessageReactionRemoveEmojiEventArgs {

public:
	MessageReactionRemoveEmojiEventArgs(const nJson &json);
	~MessageReactionRemoveEmojiEventArgs();

public:
	Guild *m_Guild;
	Channel *m_Channel;
	Message *m_Message;
	Emoji *m_Emoji;

};

