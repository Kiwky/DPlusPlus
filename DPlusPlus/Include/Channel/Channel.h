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

class Channel {

public:
	Channel();
	Channel(const Snowflake &id);
	Channel(const nJson &json);

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

