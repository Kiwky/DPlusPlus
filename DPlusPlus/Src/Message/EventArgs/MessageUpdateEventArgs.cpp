#include "Message/EventArgs/MessageUpdateEventArgs.h"

#include "Guild/Guild.h"
#include "Member/Member.h"
#include "User/User.h"
#include "Channel/Channel.h"
#include "Message/Message.h"

MessageUpdateEventArgs::MessageUpdateEventArgs(const nJson &json) {
	m_message = new Message(json);
	m_channel = new Channel(m_message->m_channelId);
	m_guild = new Guild(m_message->m_guildId);

	m_member = new Member();
	*m_member = m_guild->GetMember(m_message->m_user->m_id);
}

MessageUpdateEventArgs::~MessageUpdateEventArgs() {
	delete m_guild;
	delete m_member;
	delete m_channel;
	delete m_message;
}
