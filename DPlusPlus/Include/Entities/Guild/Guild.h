#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"
#include "Snowflake.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class Member;

class Guild {

public:
	Guild() {}
	Guild(const Snowflake &id);
	Guild(const nJson &json);

public:
	Member GetMember(const Snowflake &id);

public:
	Snowflake m_Id;
	Snowflake m_OwnerId;
	Snowflake m_AfkChannelId;
	Snowflake m_WidgetChannelId;
	Snowflake m_ApplicationId;
	Snowflake m_SystemChannelId;
	Snowflake m_RulesChannelId;
	Snowflake m_PublicUpdatesChannelId;
	int m_AfkTimeout;
	int m_VerificationLevel;
	int m_DefaultMessageNotifications;
	int m_ExplicitContentFilter;
	int m_MfaLevel;
	int m_SystemChannelFlags;
	int m_MemberCount;
	int m_MaxPresences;
	int m_MaxMembers;
	int m_PremiumTier;
	int m_PremiumSubscriptionCount;
	int m_MaxVideoChannelUsers;
	int m_ApproximateMemberCount;
	int m_ApproximatePresenceCount;
	bool m_Owner;
	bool m_WidgetEnabled;
	bool m_Large;
	bool m_Unavailable;
	std::string m_Name;
	std::string m_Icon;
	std::string m_IconHash;
	std::string m_Splash;
	std::string m_DiscoverySplash;
	std::string m_Permissions;
	std::string m_Regions;
	std::string m_JoinedAt;
	std::string m_VanityUrlCode;
	std::string m_Description;
	std::string m_Banner;
	std::string m_PreferredLocale;
	//std::vector<Channel *> m_Channels;
	//std::vector<Member *> m_Members;
	//std::vector<Emoji *> m_Emojis;
	//WelcomeScreen welcome_screen;			TODO
	//std::vector<VoiceState> voice_states; TODO
	//std::vector<Role> roles;				TODO
	//std::vector<Feature> features;		TODO

};

