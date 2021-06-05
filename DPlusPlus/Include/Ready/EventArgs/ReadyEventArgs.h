#pragma once

#include "nlohmann/json.hpp"

#include "Globals.h"

using nJson = nlohmann::json;

class ReadyEventArgs {

public:
	ReadyEventArgs(const nJson &json);

public:
	int m_GatewayVersion;
	std::string m_SessionId;

};

