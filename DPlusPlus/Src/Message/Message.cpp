#include "Message/Message.h"

#include "User/User.h"
#include "Embed/Embed.h"

Message::Message(const nJson &json) {
	if(json.contains("author"))
		m_User = new User(json["author"]);

	GetJson(json, "id",					/**/ m_Id);
	GetJson(json, "channel_id",			/**/ m_ChannelId);
	GetJson(json, "guild_id",			/**/ m_GuildId);
	GetJson(json, "webhook_id",			/**/ m_WebhookId);
	GetJson(json, "flags",				/**/ m_Flags);
	GetJson(json, "type",				/**/ m_Type);
	GetJson(json, "content",			/**/ m_Content);
	GetJson(json, "timestamp",			/**/ m_Timestamp);
	GetJson(json, "edited_timestamp",	/**/ m_EditedTimestamp);
	GetJson(json, "tts",				/**/ m_Tts);
	GetJson(json, "mention_everyone",	/**/ m_MentionEveryone);
	GetJson(json, "pinned",				/**/ m_Pinned);
}

void Message::ToJson(nJson &j) {
	nJson jsonEmbed;
	if(m_Embeds != nullptr && (m_Embeds->m_Description.length() > 0 || m_Embeds->m_Fields.size()) > 0)
		m_Embeds->ToJson(jsonEmbed);

	j = nJson{
		{"content",	m_Content	},
		{"embed",	jsonEmbed	},
	};
}

void Message::ModifyMessage(Message &message) {
	nJson jsonMessage;
	message.ToJson(jsonMessage);

	API_Call("/channels/" + m_ChannelId + "/messages/" + m_Id, methods::PATCH, jsonMessage.dump());
}

void Message::DeleteMessage() {
	API_Call("/channels/" + m_ChannelId + "/permissions/" + m_Id, methods::DEL);
}
