#pragma once

#include <string>
#include <vector>
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
class Embed;
class Channel;

class Channel {

public:
	Channel() {};
	Channel(const Snowflake &id);
	Channel(const nJson &json);

public:
	void ToJson(nJson &json);

	/**
	 * Get message by id. [VIEW_CHANNEL]
	 *
	 * @messageId			The id of message.
	 */
	Message GetMessage(const Snowflake &messageId);

	/**
	 * Get message by id. [VIEW_CHANNEL]
	 *
	 * @channelId			The id of the channel.
	 * @messageId			The id of the message.
	 */
	static Message GetMessage(const Snowflake &channelId, const Snowflake &messageId);

	/**
	 * Get list of messages. [VIEW_CHANNEL]
	 *
	 * @limit				Number of messages [Max 100].
	 */
	std::vector<Message> GetMessages(int limit = 100);

	/**
	 * Get list of messages. [VIEW_CHANNEL]
	 *
	 * @channelId			The id of the channel.
	 * @limit				Number of messages [Max 100].
	 */
	static std::vector<Message> GetMessages(const Snowflake &channelId, int limit = 100);

	/**
	 * Send message in channel. [SEND_MESSAGES]
	 *
	 * @content				Message text content.
	 * @embed				Optionally embed object.
	 */
	void SendMessage(const std::string &content, Embed *embed = nullptr);

	/**
	 * Send message in channel. [SEND_MESSAGES]
	 *
	 * @channelId			The id of the channel.
	 * @content				Message text content.
	 * @embed				Optionally embed object.
	 */
	static void SendMessage(const Snowflake &channelId, const std::string &content, Embed *embed = nullptr);

	/**
	 * Update a channel's settings. [MANAGE_CHANNELS]
	 *
	 * @name				New channel name.
	 * @topic				New channel topic.
	 */
	void ModifyChannel(const std::string &name, const std::string &topic);

	/**
	 * Update a channel's settings. [MANAGE_CHANNELS]
	 *
	 * @channelId			The id of the channel.
	 * @name				New channel name.
	 * @topic				New channel topic.
	 */
	void ModifyChannel(const Snowflake &channelId, const std::string &name, const std::string &topic);

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

