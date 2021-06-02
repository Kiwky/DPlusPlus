#include "Channel/Channel.h"

#include "Message/Message.h"

Channel::Channel(const Snowflake &id) {
	*this = Channel(API_Call("/channels/" + id, methods::GET));
}

Channel::Channel(const nJson &data) {
	GetJson(data, "id",					/**/ m_id);
	GetJson(data, "guild_id",			/**/ m_guildId);
	GetJson(data, "last_message_id",	/**/ m_lastMessageId);
	GetJson(data, "position",			/**/ m_position);
	GetJson(data, "bitrate",			/**/ m_bitrate);
	GetJson(data, "user_limit",			/**/ m_userLimit);
	GetJson(data, "type",				/**/ m_type);
	GetJson(data, "name",				/**/ m_name);
	GetJson(data, "topic",				/**/ m_topic);
	GetJson(data, "icon",				/**/ m_icon);
	GetJson(data, "nsfw",				/**/ m_nsfw);
}

Message Channel::GetMessage(const Snowflake &messageId) {
	return Message(API_Call("/channels/" + m_id + "/messages/" + messageId, methods::GET));
}

Message Channel::GetMessage(const Snowflake &channelId, const Snowflake &messageId) {
	return Message(API_Call("/channels/" + channelId + "/messages/" + messageId, methods::GET));
}
