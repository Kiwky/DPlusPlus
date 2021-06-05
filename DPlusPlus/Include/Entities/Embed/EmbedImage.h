#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"

using nJson = nlohmann::json;

class EmbedImage {

public:
	void ToJson(nJson &j);

public:
	std::string m_Url;
	std::string m_ProxyUrl;
	int m_Height;
	int m_Width;

};

