#include "Entities/Message/EventArgs/MessageUpdateEventArgs.h"

#include "Entities/Guild/Guild.h"
#include "Entities/Member/Member.h"
#include "Entities/User/User.h"
#include "Entities/Channel/Channel.h"
#include "Entities/Message/Message.h"

MessageUpdateEventArgs::MessageUpdateEventArgs(const nJson &json) {
	m_Message = new Message(json);
	m_Channel = new Channel(m_Message->m_ChannelId);
	m_Guild = new Guild(m_Message->m_GuildId);

	m_Member = new Member();
	*m_Member = m_Guild->GetMember(m_Message->m_User->m_Id);
}

MessageUpdateEventArgs::~MessageUpdateEventArgs() {
	delete m_Guild;
	delete m_Member;
	delete m_Channel;
	delete m_Message;
}
