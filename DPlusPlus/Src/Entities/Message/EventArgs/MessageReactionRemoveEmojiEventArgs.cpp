#include "Entities/Message/EventArgs/MessageReactionRemoveEmojiEventArgs.h"

#include "Entities/Guild/Guild.h"
#include "Entities/Channel/Channel.h"
#include "Entities/Message/Message.h"
#include "Entities/Emoji/Emoji.h"

MessageReactionRemoveEmojiEventArgs::MessageReactionRemoveEmojiEventArgs(const nJson &json) {
	m_Channel = new Channel(json["channel_id"].get<Snowflake>());
	m_Guild = new Guild(json["Entities/Guild_id"].get<Snowflake>());

	m_Message = new Message();
	*m_Message = m_Channel->GetMessage(json["message_id"].get<Snowflake>());

	// TODO EMOJI
}

MessageReactionRemoveEmojiEventArgs::~MessageReactionRemoveEmojiEventArgs() {
	delete m_Channel;
	delete m_Guild;
	delete m_Message;
}
