#include "Message/Message.h"

#include "User/User.h"
#include "Embed/Embed.h"

Message::Message(const nJson &json) {
	if(json.contains("author"))
		m_user = new User(json["author"]);

	GetJson(json, "id",					/**/ m_id);
	GetJson(json, "channel_id",			/**/ m_channelId);
	GetJson(json, "guild_id",			/**/ m_guildId);
	GetJson(json, "webhook_id",			/**/ m_webhookId);
	GetJson(json, "flags",				/**/ m_flags);
	GetJson(json, "type",				/**/ m_type);
	GetJson(json, "content",			/**/ m_content);
	GetJson(json, "timestamp",			/**/ m_timestamp);
	GetJson(json, "edited_timestamp",	/**/ m_editedTimestamp);
	GetJson(json, "tts",				/**/ m_tts);
	GetJson(json, "mention_everyone",	/**/ m_mentionEveryone);
	GetJson(json, "pinned",				/**/ m_pinned);
}

#include <iostream>

void Message::ToJson(nJson &j) {
	nJson jsonEmbed;
	if(m_embeds != nullptr && (m_embeds->m_description.length() > 0 || m_embeds->m_fields.size()) > 0)
		m_embeds->ToJson(jsonEmbed);

	j = nJson{
		{"content",	m_content	},
		{"embed",	jsonEmbed	},
	};
}

#include <iostream>

void Message::ModifyMessage(Message &message) {
	return ModifyMessage(m_channelId, m_id, message);
}

void Message::ModifyMessage(const Snowflake &channelId, const Snowflake &messageId, Message &message) {
	nJson jsonMessage;
	message.ToJson(jsonMessage);

	API_Call("/channels/" + channelId + "/messages/" + messageId, methods::PATCH, jsonMessage.dump());
}

void Message::DeleteMessage() {
	DeleteMessage(m_channelId, m_id);
}

void Message::DeleteMessage(const Snowflake &channelId, const Snowflake &messageId) {
	API_Call("/channels/" + channelId + "/permissions/" + messageId, methods::DEL);
}

