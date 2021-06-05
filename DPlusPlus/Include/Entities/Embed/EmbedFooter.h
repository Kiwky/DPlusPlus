#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"

using nJson = nlohmann::json;

class EmbedFooter {

public:
	void ToJson(nJson &j);

public:
	std::string m_Text;
	std::string m_IconUrl;
	std::string m_ProxyIconUrl;

};

