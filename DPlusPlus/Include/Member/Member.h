#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"
#include "Snowflake.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class User;

class Member {

public:
	Member() {}
	Member(const Snowflake &id);
	Member(const nJson &json);

public:
	User *m_User;
	bool m_Deaf;
	bool m_Mute;
	bool m_Pending;
	std::string m_Nick;
	std::string m_JoinedAt;
	std::string m_PremiumSince;
	std::string m_Permissions;

};

