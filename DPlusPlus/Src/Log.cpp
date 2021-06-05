#include "Log.h"

void Log::Print(int color, const std::string &type, const std::string &message) {
#ifdef _WIN32
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, color);
	std::cout << type << " ";
	SetConsoleTextAttribute(hConsole, COLOR_RESET);
	std::cout << message << "\n";
#else
	std::cout << color << type << " " << COLOR_RESET << message << std::endl;
#endif
}

void Log::Warning(const std::string &message) {
	Print(COLOR_YELOW, "[WARNING]", message);
}

void Log::Error(const std::string &message) {
	Print(COLOR_RED, "[ERROR]", message);
}

void Log::Info(const std::string &message) {
	Print(COLOR_MAGENTA, "[INFO]", message);
}

void Log::Succes(const std::string &message) {
	Print(COLOR_GREEN, "[SUCCES]", message);
}

void Log::Event(const std::string &eventName) {
	Print(COLOR_GREEN, "[" + eventName + "]", "Called!");
}

