#include "Entities/Message/EventArgs/MessageCreateEventArgs.h"

#include "Entities/Message/Message.h"
#include "Entities/Channel/Channel.h"
#include "Entities/Guild/Guild.h"

MessageCreateEventArgs::MessageCreateEventArgs(const nJson &json) {
	m_Message = new Message(json);
	m_Channel = new Channel(m_Message->m_ChannelId);
	m_Guild = new Guild(m_Message->m_GuildId);
}

MessageCreateEventArgs::~MessageCreateEventArgs() {
	delete m_Message;
	delete m_Channel;
	delete m_Guild;
}
