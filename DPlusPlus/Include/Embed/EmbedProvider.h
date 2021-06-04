#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"

using nJson = nlohmann::json;

class EmbedProvider {

public:
	void ToJson(nJson &j);

public:
	std::string m_Name;
	std::string m_Url;

};

