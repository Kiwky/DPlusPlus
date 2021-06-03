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
	 * Get list of messages. [VIEW_CHANNEL]
	 *
	 * @limit				Number of messages [Max 100].
	 */
	std::vector<Message> GetMessages(int limit = 100);

	/**
	 * Send message in channel. [SEND_MESSAGES]
	 *
	 * @content				Message text content.
	 * @embed				Optionally embed object.
	 */
	Message SendMessage(const std::string &content, Embed *embed = nullptr);

	/**
	 * Update a channel's settings. [MANAGE_CHANNELS]
	 *
	 * @name				New channel name.
	 * @topic				New channel topic.
	 */
	void ModifyChannel(const std::string &name, const std::string &topic);

	/**
	 * Delete multiple messages in a single request. [MANAGE_MESSAGES]
	 *
	 * @messages			List of messages to delete.
	 */
	void DeleteMessageBulk(const std::vector<Message> &messages);
	
public:
	Snowflake m_id;
	Snowflake m_guildId;
	Snowflake m_lastMessageId;
	int m_position;
	int m_bitrate;
	int m_userLimit;
	bool m_nsfw;
	ChannelType m_type;
	std::string m_name;
	std::string m_topic;
	std::string m_icon;
	// vector<overwrite> permission_overwrites;

};

