#include "Message/EventArgs/MessageBulkDeleteEventArgs.h"

#include "Channel/Channel.h"
#include "Guild/Guild.h"

MessageBulkDeleteEventArgs::MessageBulkDeleteEventArgs(const nJson &json) {
	m_channel = new Channel(json["channel_id"].get<Snowflake>());
	m_guild = new Guild(m_channel->m_guildId);

	m_ids = json["ids"].get<std::vector<Snowflake>>();
}

MessageBulkDeleteEventArgs::~MessageBulkDeleteEventArgs() {
	delete m_channel;
	delete m_guild;
}
