#pragma once

#include <string>

#include "nlohmann/json.hpp"

using nJson = nlohmann::json;

extern std::string GLOBAL_GATEWAY_URL;
extern std::string GLOBAL_API_URL;

constexpr unsigned int hash_string(const char *str, int h = 0) {
	return !str[h] ? 5381 : (hash_string(str, h + 1) * 33) ^ str[h];
}

template <typename T>
void GetJson(const nJson &j, const char *key, T &val) {
	if(j.contains(key) == false || j.at(key).is_null()) {
		val = T{};
	}
	else {
		val = j.value(key, T{});
	}
}