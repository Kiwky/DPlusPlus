#pragma once

#include <iostream>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#endif 

#ifdef _WIN32
#define COLOR_RESET		7
#define COLOR_RED		4
#define COLOR_GREEN		2
#define COLOR_YELOW		6	
#define COLOR_BLUE		9
#define COLOR_MAGENTA	5
#define COLOR_CYAN		11
#define COLOR_WHITE		15
#else
#define COLOR_RESET		"\x1B[0m"
#define COLOR_RED		"\x1B[31m"
#define COLOR_GREEN		"\x1B[32m"
#define COLOR_YELOW		"\x1B[33m"
#define COLOR_BLUE		"\x1B[34m"
#define COLOR_MAGENTA	"\x1B[35m"
#define COLOR_CYAN		"\x1B[36m"	
#define COLOR_WHITE		"\x1B[37m"
#endif

class Log {

private:
	static void Print(int color, const std::string &type, const std::string &message);

public:
	static void Warning(const std::string &message);
	static void Error(const std::string &message);
	static void Info(const std::string &message);
	static void Succes(const std::string &message);
	static void Event(const std::string &eventName);

};