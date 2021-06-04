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
	Snowflake m_Id;
	int m_PremiumType;
	int m_PublicFlags;
	bool m_Bot;
	bool m_System;
	bool m_MfaEnabled;
	bool m_Verified;
	UserFlags m_Flags;
	std::string m_Username;
	std::string m_Discriminator;
	std::string m_Avatar;
	std::string m_Locale;
	std::string m_Email;

};

