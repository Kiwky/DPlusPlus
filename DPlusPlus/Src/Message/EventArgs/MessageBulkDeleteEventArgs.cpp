#include "Message/EventArgs/MessageBulkDeleteEventArgs.h"

#include "Channel/Channel.h"
#include "Guild/Guild.h"

MessageBulkDeleteEventArgs::MessageBulkDeleteEventArgs(const nJson &json) {
	m_Channel = new Channel(json["channel_id"].get<Snowflake>());
	m_Guild = new Guild(m_Channel->m_GuildId);

	m_Ids = json["ids"].get<std::vector<Snowflake>>();
}

MessageBulkDeleteEventArgs::~MessageBulkDeleteEventArgs() {
	delete m_Channel;
	delete m_Guild;
}
