#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"

using nJson = nlohmann::json;

class EmbedAuthor {

public:
	void ToJson(nJson &j);

public:
	std::string m_Name;
	std::string m_Url;
	std::string m_IconUrl;
	std::string m_ProxyIconUrl;


};

