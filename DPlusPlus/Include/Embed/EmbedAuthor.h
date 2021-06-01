#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"

using nJson = nlohmann::json;

class EmbedAuthor {

public:
	void ToJson(nJson &j);

public:
	std::string m_name;
	std::string m_url;
	std::string m_iconUrl;
	std::string m_proxyIconUrl;


};

