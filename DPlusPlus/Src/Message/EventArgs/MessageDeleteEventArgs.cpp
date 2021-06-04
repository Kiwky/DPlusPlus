#include "Message/EventArgs/MessageDeleteEventArgs.h"

#include "Channel/Channel.h"
#include "Guild/Guild.h"

MessageDeleteEventArgs::MessageDeleteEventArgs(const nJson &json) {
	Snowflake channelId = json["channel_id"];

	m_Id = json["id"];
	m_Channel = new Channel(channelId);
	m_Guild = new Guild(m_Channel->m_GuildId);
}

MessageDeleteEventArgs::~MessageDeleteEventArgs() {
	delete m_Channel;
	delete m_Guild;
}
