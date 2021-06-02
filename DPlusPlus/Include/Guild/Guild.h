#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"
#include "Snowflake.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class Guild {

public:
	Guild() {}
	Guild(const Snowflake &id);
	Guild(const nJson &json);

public:
	Snowflake m_id;
	Snowflake m_ownerId;
	Snowflake m_afkChannelId;
	Snowflake m_widgetChannelId;
	Snowflake m_applicationId;
	Snowflake m_systemChannelId;
	Snowflake m_rulesChannelId;
	Snowflake m_publicUpdatesChannelId;
	int m_afkTimeout;
	int m_verificationLevel;
	int m_defaultMessageNotifications;
	int m_explicitContentFilter;
	int m_mfaLevel;
	int m_systemChannelFlags;
	int m_memberCount;
	int m_maxPresences;
	int m_maxMembers;
	int m_premiumTier;
	int m_premiumSubscriptionCount;
	int m_maxVideoChannelUsers;
	int m_approximateMemberCount;
	int m_approximatePresenceCount;
	bool m_owner;
	bool m_widgetEnabled;
	bool m_large;
	bool m_unavailable;
	std::string m_name;
	std::string m_icon;
	std::string m_iconHash;
	std::string m_splash;
	std::string m_discoverySplash;
	std::string m_permissions;
	std::string m_regions;
	std::string m_joinedAt;
	std::string m_vanityUrlCode;
	std::string m_description;
	std::string m_banner;
	std::string m_preferredLocale;
	//std::vector<Channel *> m_channels;
	//std::vector<Member *> m_members;
	//std::vector<Emoji *> m_emojis;
	//WelcomeScreen welcome_screen;			TODO
	//std::vector<VoiceState> voice_states; TODO
	//std::vector<Role> roles;				TODO
	//std::vector<Feature> features;		TODO

};

