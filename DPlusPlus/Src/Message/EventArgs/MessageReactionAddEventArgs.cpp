#include "Message/EventArgs/MessageReactionAddEventArgs.h"

#include "Message/Message.h"
#include "Channel/Channel.h"
#include "Member/Member.h"
#include "Guild/Guild.h"
#include "Emoji/Emoji.h"

MessageReactionAddEventArgs::MessageReactionAddEventArgs(const nJson &json) {
	m_channel = new Channel(json["channel_id"].get<Snowflake>());
	m_guild = new Guild(json["guild_id"].get<Snowflake>());
	
	m_message = new Message();
	*m_message = m_channel->GetMessage(json["message_id"].get<Snowflake>());
	
	m_member = new Member();
	*m_member = m_guild->GetMember(json["user_id"].get<Snowflake>());

	// TODO EMOJI
}

MessageReactionAddEventArgs::~MessageReactionAddEventArgs() {
	delete m_message;
	delete m_channel;
	delete m_member;
	delete m_guild;
	//delete m_emoji;
}
