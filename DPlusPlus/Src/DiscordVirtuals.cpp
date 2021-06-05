#include "Discord.h"

void Discord::OnReady(const ReadyEventArgs &ready) {
	Log::Event("OnReady");
}

void Discord::OnMessageCreated(const MessageCreateEventArgs &message) {
	Log::Event("OnMessageCreated");
}

void Discord::OnMessageDeleted(const MessageDeleteEventArgs &message) {
	Log::Event("OnMessageDeleted");
}

void Discord::OnMessageUpdate(const MessageUpdateEventArgs &message) {
	Log::Event("OnMessageUpdate");
}

void Discord::OnMessageDeletedBulk(const MessageBulkDeleteEventArgs &message) {
	Log::Event("OnMessageDeletedBulk");
}

void Discord::OnMessageReactionAdd(const MessageReactionAddEventArgs &message) {
	Log::Event("OnMessageReactionAdd");
}

void Discord::OnMessageReactionRemoved(const MessageReactionRemoveEventArgs &message) {
	Log::Event("OnMessageReactionRemoved");
}

void Discord::OnMessageReactionClear(const MessageReactionsClearEventArgs &message) {
	Log::Event("OnMessageReactionClear");
}

void Discord::OnMessageReactionRemoveEmoji(const MessageReactionRemoveEmojiEventArgs &message) {
	Log::Event("OnMessageReactionRemoveEmoji");
}

void Discord::OnGuildCreated(const GuildCreateEventArgs &guild) {
	Log::Event("OnGuildCreated");
}