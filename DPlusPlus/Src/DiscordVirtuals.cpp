#include "Discord.h"

void Discord::OnMessageCreated(const Message &message) {
	Log::Info("[OnMessageCreated] Was called!");
}

void Discord::OnMessageDeleted(const Message &message) {
	Log::Info("[OnMessageDeleted] Was called!");
}