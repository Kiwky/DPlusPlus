#include "Channel/Channel.h"

#include "Message/Message.h"
#include "Embed/Embed.h"
#include "Channel/Channel.h"

Channel::Channel(const Snowflake &id) {
	*this = Channel(API_Call("/channels/" + id, methods::GET));
}

Channel::Channel(const nJson &json) {
	GetJson(json, "id",					/**/ m_id);
	GetJson(json, "guild_id",			/**/ m_guildId);
	GetJson(json, "last_message_id",	/**/ m_lastMessageId);
	GetJson(json, "position",			/**/ m_position);
	GetJson(json, "bitrate",			/**/ m_bitrate);
	GetJson(json, "user_limit",			/**/ m_userLimit);
	GetJson(json, "type",				/**/ m_type);
	GetJson(json, "name",				/**/ m_name);
	GetJson(json, "topic",				/**/ m_topic);
	GetJson(json, "icon",				/**/ m_icon);
	GetJson(json, "nsfw",				/**/ m_nsfw);
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
	return Message(API_Call("/channels/" + m_id + "/messages/" + messageId, methods::GET));
}

std::vector<Message> Channel::GetMessages(int limit /*= 100*/) {
	std::vector<Message> messages;

	nJson json_result = API_Call("/channels/" + m_id + "/messages?limit=" + std::to_string(limit), methods::GET);

	for(auto iter = json_result.begin(); iter != json_result.end(); ++iter) {
		messages.emplace_back(Message(*iter));
	}

	return messages;
}

Message Channel::SendMessage(const std::string &content, Embed *embed /*= nullptr*/) {
	nJson jsonObject;
	Message message;

	message.m_content = content;
	if(embed != nullptr)
		message.m_embeds = embed;

	message.ToJson(jsonObject);

	return Message(API_Call("/channels/" + m_id + "/messages", methods::POST, jsonObject.dump()));
}

void Channel::ModifyChannel(const std::string &name, const std::string &topic) {
	nJson jsonChannel;
	jsonChannel = nJson{
		{ "name",	name	},
		{ "topic",	topic	}
	};

	API_Call("/channels/" + m_id, methods::PATCH, jsonChannel.dump());
}

void Channel::DeleteMessageBulk(const std::vector<Message> &messages) {
	nJson jsonMessages;

	for(auto iter = messages.begin(); iter != messages.end(); ++iter) {
		jsonMessages["messages"].push_back(iter->m_id);
	}

	// TODO BUG
	// Log::Info("[BUG] Fake error.");

	API_Call("/channels/" + m_id + "/messages/bulk-delete", methods::POST, jsonMessages.dump());
}
