#include "Channel/Channel.h"

#include "Message/Message.h"
#include "Embed/Embed.h"
#include "Channel/Channel.h"

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

void Channel::ToJson(nJson &json) {
	if(m_bitrate > 0)
		json["bitrate"] = m_bitrate;

	json = nJson{
		{ "id",				m_id			},
		{ "guild_id",		m_guildId		},
		{ "last_message_id",m_lastMessageId	},
		{ "position",		m_position		},
		{ "user_limit",		m_userLimit		},
		{ "type",			m_type			},
		{ "name",			m_name			},
		{ "topic",			m_topic			},
		{ "icon",			m_icon			},
		{ "nsfw",			m_nsfw			}
	};
}

Message Channel::GetMessage(const Snowflake &messageId) {
	return GetMessage(m_id, messageId);
}

Message Channel::GetMessage(const Snowflake &channelId, const Snowflake &messageId) {
	return Message(API_Call("/channels/" + channelId + "/messages/" + messageId, methods::GET));
}

std::vector<Message> Channel::GetMessages(int limit /*= 100*/) {
	return GetMessages(m_id, limit);
}

std::vector<Message> Channel::GetMessages(const Snowflake &channelId, int limit /*= 100*/) {
	std::vector<Message> messages;

	nJson json_result = API_Call("/channels/" + channelId + "/messages?limit=" + std::to_string(limit), methods::GET);

	for(auto iter = json_result.begin(); iter != json_result.end(); ++iter) {
		messages.emplace_back(Message(*iter));
	}

	return messages;
}

void Channel::SendMessage(const std::string &content, Embed *embed /*= nullptr*/) {
	SendMessage(m_id, content, embed);
}

void Channel::SendMessage(const Snowflake &channelId, const std::string &content, Embed *embed /*= nullptr*/) {
	nJson jsonObject;
	Message message;

	message.m_content = content;
	if(embed != nullptr)
		message.m_embeds = embed;

	message.ToJson(jsonObject);
	API_Call("/channels/" + channelId + "/messages", methods::POST, jsonObject.dump());
}

void Channel::ModifyChannel(const std::string &name, const std::string &topic) {
	ModifyChannel(m_id, name, topic);
}

void Channel::ModifyChannel(const Snowflake &channelId, const std::string &name, const std::string &topic) {
	nJson jsonChannel;
	//channel.ToJson(jsonObject);
	jsonChannel = nJson{
		{ "name",	name	},
		{ "topic",	topic	}
	};

	API_Call("/channels/" + channelId, methods::PATCH, jsonChannel.dump());
}
