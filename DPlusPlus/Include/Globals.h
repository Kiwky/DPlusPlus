#pragma once

#include <string>

extern std::string GLOBAL_GATEWAY_URL;

constexpr unsigned int hash_string(const char *str, int h = 0) {
	return !str[h] ? 5381 : (hash_string(str, h + 1) * 33) ^ str[h];
}