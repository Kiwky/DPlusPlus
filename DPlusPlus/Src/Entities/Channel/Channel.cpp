#include "Entities/Channel/Channel.h"

#include "Entities/Message/Message.h"
#include "Entities/Embed/Embed.h"
#include "Entities/Channel/Channel.h"

Channel::Channel(const Snowflake &id) {
	*this = Channel(API_Call("/channels/" + id, methods::GET));
}

Channel::Channel(const nJson &json) {
	GetJson(json, "id",					/**/ m_Id);
	GetJson(json, "Entities/Guild_id",			/**/ m_GuildId);
	GetJson(json, "last_message_id",	/**/ m_LastMessageId);
	GetJson(json, "position",			/**/ m_Position);
	GetJson(json, "bitrate",			/**/ m_Bitrate);
	GetJson(json, "user_limit",			/**/ m_UserLimit);
	GetJson(json, "type",				/**/ m_Type);
	GetJson(json, "name",				/**/ m_Name);
	GetJson(json, "topic",				/**/ m_Topic);
	GetJson(json, "icon",				/**/ m_Icon);
	GetJson(json, "nsfw",				/**/ m_Nsfw);
}

void Channel::ToJson(nJson &json) {
	if(m_Bitrate > 0)
		json["bitrate"] = m_Bitrate;

	json = nJson{
		{ "id",				m_Id			},
		{ "Entities/Guild_id",		m_GuildId		},
		{ "last_message_id",m_LastMessageId	},
		{ "position",		m_Position		},
		{ "user_limit",		m_UserLimit		},
		{ "type",			m_Type			},
		{ "name",			m_Name			},
		{ "topic",			m_Topic			},
		{ "icon",			m_Icon			},
		{ "nsfw",			m_Nsfw			}
	};
}

Message Channel::GetMessage(const Snowflake &messageId) {
	return Message(API_Call("/channels/" + m_Id + "/messages/" + messageId, methods::GET));
}

std::vector<Message> Channel::GetMessages(int limit /*= 100*/) {
	std::vector<Message> messages;

	nJson json_result = API_Call("/channels/" + m_Id + "/messages?limit=" + std::to_string(limit), methods::GET);

	for(auto iter = json_result.begin(); iter != json_result.end(); ++iter) {
		messages.emplace_back(Message(*iter));
	}

	return messages;
}

Message Channel::SendMessage(const std::string &content, Embed *embed /*= nullptr*/) {
	nJson jsonObject;
	Message message;

	message.m_Content = content;
	if(embed != nullptr)
		message.m_Embeds = embed;

	message.ToJson(jsonObject);

	return Message(API_Call("/channels/" + m_Id + "/messages", methods::POST, jsonObject.dump()));
}

void Channel::ModifyChannel(const std::string &name, const std::string &topic) {
	nJson jsonChannel;
	jsonChannel = nJson{
		{ "name",	name	},
		{ "topic",	topic	}
	};

	API_Call("/channels/" + m_Id, methods::PATCH, jsonChannel.dump());
}

void Channel::DeleteMessageBulk(const std::vector<Message> &messages) {
	nJson jsonMessages;

	for(auto iter = messages.begin(); iter != messages.end(); ++iter) {
		jsonMessages["messages"].push_back(iter->m_Id);
	}

	// TODO BUG
	// Log::Info("[BUG] Fake error.");

	API_Call("/channels/" + m_Id + "/messages/bulk-delete", methods::POST, jsonMessages.dump());
}
