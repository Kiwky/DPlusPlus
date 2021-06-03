#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"
#include "Snowflake.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

enum class UserFlags {
	kNone = 0,
	kDiscordEmployee,
	kPartnered,
	kHypeSquad,
	kBugHunter1,
	kHouseBravery,
	kHouseBrilliance,
	kHouseBalance,
	kEarlySupport,
	kTeamUser,
	kSystem,
	kBugHunter2,
	kVerifiedBot,
	kEarlyBotDev
};

class User {

public:
	User(const Snowflake &id);
	User(const nJson &json);

public:
	Snowflake m_id;
	int m_premiumType;
	int m_publicFlags;
	bool m_bot;
	bool m_system;
	bool m_mfaEnabled;
	bool m_verified;
	UserFlags m_flags;
	std::string m_username;
	std::string m_discriminator;
	std::string m_avatar;
	std::string m_locale;
	std::string m_email;

};

