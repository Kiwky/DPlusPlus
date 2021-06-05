#include "Entities/Message/EventArgs/MessageReactionAddEventArgs.h"

#include "Entities/Message/Message.h"
#include "Entities/Channel/Channel.h"
#include "Entities/Member/Member.h"
#include "Entities/Guild/Guild.h"
#include "Entities/Emoji/Emoji.h"

MessageReactionAddEventArgs::MessageReactionAddEventArgs(const nJson &json) {
	m_Channel = new Channel(json["channel_id"].get<Snowflake>());
	m_Guild = new Guild(json["Entities/Guild_id"].get<Snowflake>());
	
	m_Message = new Message();
	*m_Message = m_Channel->GetMessage(json["message_id"].get<Snowflake>());
	
	m_Member = new Member();
	*m_Member = m_Guild->GetMember(json["user_id"].get<Snowflake>());

	// TODO EMOJI
}

MessageReactionAddEventArgs::~MessageReactionAddEventArgs() {
	delete m_Message;
	delete m_Channel;
	delete m_Member;
	delete m_Guild;
	//delete m_Emoji;
}
