#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"
#include "Snowflake.h"

using nJson = nlohmann::json;

class User {

public:
	User(const Snowflake &id);
	User(const nJson &data);

public:
	Snowflake m_id;

};

