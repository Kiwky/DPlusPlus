#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"
#include "Snowflake.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class User {

public:
	User(const Snowflake &id);
	User(const nJson &json);

public:
	Snowflake m_id;

};

