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
	User *m_user;
	bool m_deaf;
	bool m_mute;
	bool m_pending;
	std::string m_nick;
	std::string m_joinedAt;
	std::string m_premiumSince;
	std::string m_permissions;

};

