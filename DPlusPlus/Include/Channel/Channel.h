#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"
#include "Snowflake.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

enum class ChannelType {
	kGuildText = 0,
	kDm,
	kGuildVoice,
	kGroupDm,
	kGuildCategory,
	kGuildNews,
	kGuildStore
};

class Message;

class Channel {

public:
	Channel();
	Channel(const Snowflake &id);
	Channel(const nJson &json);

public:
	/**
	 * Get message by id from channel object.
	 * 
	 * @messageId			The id of message.
	 */
	Message GetMessage(const Snowflake &messageId);
	
	/**
	 * Get message id without existing channel object.
	 * 
	 * @channelId			The id of the channel.
	 * @messageId			The id of the message.
	 */
	static Message GetMessage(const Snowflake &channelId, const Snowflake &messageId);



public:
	Snowflake m_id;
	Snowflake m_guildId;
	Snowflake m_lastMessageId;
	int m_position;
	int m_bitrate;
	int m_userLimit;
	ChannelType m_type;
	std::string m_name;
	std::string m_topic;
	std::string m_icon;
	bool m_nsfw;
	// vector<overwrite> permission_overwrites;

};

