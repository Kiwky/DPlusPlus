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

void Message::ToJson(nJson &j) {
	nJson jsonEmbed;
	//if(m_embeds->)
}
