#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"

using nJson = nlohmann::json;

class EmbedFooter {

public:
	void ToJson(nJson &j);

public:
	std::string m_text;
	std::string m_iconUrl;
	std::string m_proxyIconUrl;

};

