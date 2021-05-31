#pragma once

#include "nlohmann/json.hpp"

#include "Globals.h"
#include "Snowflake.h"

using nJson = nlohmann::json;

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
	kApplicationCommands
};

class Message {

public:
	Message() {}
	Message(const Snowflake &id);

public:
	Snowflake m_id;
	Snowflake m_channelId;
	Snowflake m_guildId;
	Snowflake m_webhookId;
	int m_flags;
	MessageType m_messageType;
	std::string m_content;
	std::string m_timestamp;
	std::string m_editedTimestamp;
	bool m_tts;
	bool m_mentionEveryone;
	bool m_pinned;
	// TODO: mentions, mention_roles, attachments, reactions, channel

};

