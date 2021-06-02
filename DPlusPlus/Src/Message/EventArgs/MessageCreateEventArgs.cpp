#include "Message/EventArgs/MessageCreateEventArgs.h"

#include "Message/Message.h"
#include "Channel/Channel.h"
#include "Guild/Guild.h"

MessageCreateEventArgs::MessageCreateEventArgs(const nJson &json) {
	m_message = new Message(json);
	m_channel = new Channel(m_message->m_channelId);
	m_guild = new Guild(m_message->m_guildId);
}

MessageCreateEventArgs::~MessageCreateEventArgs() {
	delete m_message;
	delete m_channel;
	delete m_guild;
}
