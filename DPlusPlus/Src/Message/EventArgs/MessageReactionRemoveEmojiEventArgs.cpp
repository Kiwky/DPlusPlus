#include "Message/EventArgs/MessageReactionRemoveEmojiEventArgs.h"

#include "Guild/Guild.h"
#include "Channel/Channel.h"
#include "Message/Message.h"
#include "Emoji/Emoji.h"

MessageReactionRemoveEmojiEventArgs::MessageReactionRemoveEmojiEventArgs(const nJson &json) {
	m_Channel = new Channel(json["channel_id"].get<Snowflake>());
	m_Guild = new Guild(json["guild_id"].get<Snowflake>());

	m_Message = new Message();
	*m_Message = m_Channel->GetMessage(json["message_id"].get<Snowflake>());

	// TODO EMOJI
}

MessageReactionRemoveEmojiEventArgs::~MessageReactionRemoveEmojiEventArgs() {
	delete m_Channel;
	delete m_Guild;
	delete m_Message;
}
