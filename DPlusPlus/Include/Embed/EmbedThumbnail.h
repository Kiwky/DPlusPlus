#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"

using nJson = nlohmann::json;

class EmbedThumbnail {

public:
	void ToJson(nJson &j);

public:
	std::string m_url;
	std::string m_proxyUrl;
	int m_height;
	int m_width;

};

