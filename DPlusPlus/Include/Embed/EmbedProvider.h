#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"

using nJson = nlohmann::json;

class EmbedProvider {

public:
	void ToJson(nJson &j);

public:
	std::string m_name;
	std::string m_url;

};

