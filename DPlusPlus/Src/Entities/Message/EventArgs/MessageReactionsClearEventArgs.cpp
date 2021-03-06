#include "Entities/Message/EventArgs/MessageReactionsClearEventArgs.h"

#include "Entities/Channel/Channel.h"
#include "Entities/Guild/Guild.h"
#include "Entities/Message/Message.h"

MessageReactionsClearEventArgs::MessageReactionsClearEventArgs(const nJson &json) {
	m_Channel = new Channel(json["channel_id"].get<Snowflake>());
	m_Guild = new Guild(m_Channel->m_GuildId);

	m_Message = new Message();
	*m_Message = m_Channel->GetMessage(json["message_id"].get<Snowflake>());
}

MessageReactionsClearEventArgs::~MessageReactionsClearEventArgs() {
	delete m_Channel;
	delete m_Guild;
	delete m_Message;
}
