#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"
#include "Snowflake.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

enum class MessageType {
	kDefault = 0,
	kRecipientAdd,
	kRecipientRemove,
	kCall,
	kChannelNameChange,
	kChannelIconChange,
	kChannelPinnedMessage,
	kGuildMemberJoin,
	kUserPremiumGuildSubscription,
	kUserPremiumGuildSubscriptionTier1,
	kUserPremiumGuildSubscriptionTier2,
	kUserPremiumGuildSubscriptionTier3,
	kChannelFollowAdd,
	kGuildDiscoveryDisqualified,
	kGuildDiscoveryRequalified,
	kReply,
	kApplicationCommand
};

class User;
class Embed;

class Message {

public:
	Message() {}
	Message(const nJson &json);

public:
	void ToJson(nJson &json);

	/**
	 * Update message in channel. [MANAGE_MESSAGES]
	 *
	 * @message				New message object.
	 */
	void ModifyMessage(Message &message);

	/**
	 * Delete message in channel. [MANAGE_MESSAGES]
	 */
	void DeleteMessage();

public:
	Snowflake m_Id;
	Snowflake m_ChannelId;
	Snowflake m_GuildId;
	Snowflake m_WebhookId;
	int m_Flags;
	MessageType m_Type;
	User *m_User;
	std::string m_Content;
	std::string m_Timestamp;
	std::string m_EditedTimestamp;
	bool m_Tts;
	bool m_MentionEveryone;
	bool m_Pinned;
	Embed *m_Embeds;
	//std::vector<User *> m_Mentions;
	//std::vector<Role> mention_roles;		
	//std::vector<Attachments> attachments;
	//std::vector<Reaction> reactions;	

};

