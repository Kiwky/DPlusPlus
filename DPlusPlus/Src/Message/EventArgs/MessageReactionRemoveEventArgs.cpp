#include "Message/EventArgs/MessageReactionRemoveEventArgs.h"

#include "Message/Message.h"
#include "Channel/Channel.h"
#include "Member/Member.h"
#include "Guild/Guild.h"
#include "Emoji/Emoji.h"

MessageReactionRemoveEventArgs::MessageReactionRemoveEventArgs(const nJson &json) {
	m_Channel = new Channel(json["channel_id"].get<Snowflake>());
	m_Guild = new Guild(json["guild_id"].get<Snowflake>());

	m_Message = new Message();
	*m_Message = m_Channel->GetMessage(json["message_id"].get<Snowflake>());

	m_Member = new Member();
	*m_Member = m_Guild->GetMember(json["user_id"].get<Snowflake>());

	// TODO EMOJI
}

MessageReactionRemoveEventArgs::~MessageReactionRemoveEventArgs() {
	delete m_Message;
	delete m_Channel;
	delete m_Member;
	delete m_Guild;
	//delete m_Emoji;
}
