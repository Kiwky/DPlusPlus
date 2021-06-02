#include "Discord.h"

void Discord::OnMessageCreated(const MessageCreateEventArgs &message) {
	Log::Info("[OnMessageCreated] Was called!");
}

void Discord::OnMessageDeleted(const MessageDeleteEventArgs &message) {
	Log::Info("[OnMessageDeleted] Was called!");
}
