#include "Discord.h"

void Discord::OnMessageCreated(const MessageCreateEventArgs &message) {
	Log::Info("[OnMessageCreated] Was called!");
}

void Discord::OnMessageDeleted(const MessageDeleteEventArgs &message) {
	Log::Info("[OnMessageDeleted] Was called!");
}

void Discord::OnMessageUpdate(const MessageUpdateEventArgs &message) {
	Log::Info("[OnMessageUpdate] Was called!");
}

void Discord::OnMessageDeletedBulk(const MessageBulkDeleteEventArgs &message) {
	Log::Info("[OnMessageDeletedBulk] Was called!");
}

void Discord::OnMessageReactionAdd(const MessageReactionAddEventArgs &message) {
	Log::Info("[OnMessageReactionAdd] Was called!");
}

void Discord::OnMessageReactionRemoved(const MessageReactionRemoveEventArgs &message) {
	Log::Info("[OnMessageReactionRemoved] Was called!");
}

void Discord::OnMessageReactionClear(const MessageReactionsClearEventArgs &message) {
	Log::Info("[OnMessageReactionClear] Was called!");
}