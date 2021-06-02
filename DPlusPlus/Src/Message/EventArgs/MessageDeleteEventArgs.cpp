#include "Message/EventArgs/MessageDeleteEventArgs.h"

#include "Channel/Channel.h"
#include "Guild/Guild.h"

MessageDeleteEventArgs::MessageDeleteEventArgs(const nJson &json) {
	Snowflake channelId = json["channel_id"];

	m_id = json["id"];
	m_channel = new Channel(channelId);
	m_guild = new Guild(m_channel->m_guildId);
}

MessageDeleteEventArgs::~MessageDeleteEventArgs() {
	delete m_channel;
	delete m_guild;
}
