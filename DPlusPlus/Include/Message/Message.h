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
	 * Update message in channel. [MANAGE_MESSAGES]
	 *
	 * @channelId			The id of the channel.
	 * @messageId			The if of the message.
	 * @message				New message object.
	 */
	static void ModifyMessage(const Snowflake &channelId, const Snowflake &messageId, Message &message);

	/**
	 * Delete message in channel. [MANAGE_MESSAGES]
	 */
	void DeleteMessage();

	/**
	 * Delete message in channel. [MANAGE_MESSAGES]
	 *
	 * @channelId			The id of the channel.
	 * @messageId			The if of the message.
	 */
	static void DeleteMessage(const Snowflake &channelId, const Snowflake &messageId);

public:
	Snowflake m_id;
	Snowflake m_channelId;
	Snowflake m_guildId;
	Snowflake m_webhookId;
	int m_flags;
	MessageType m_type;
	User *m_user;
	//Member member;						
	std::string m_content;
	std::string m_timestamp;
	std::string m_editedTimestamp;
	bool m_tts;
	bool m_mentionEveryone;
	bool m_pinned;
	Embed *m_embeds;
	//std::vector<User *> m_mentions;
	//std::vector<Role> mention_roles;		
	//std::vector<Attachments> attachments;
	//std::vector<Reaction> reactions;	

};

