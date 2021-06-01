#include "Message/EventArgs/MessageCreateEventArgs.h"

MessageCreateEventArgs::MessageCreateEventArgs(const nJson &json) {

}

MessageCreateEventArgs::~MessageCreateEventArgs() {
	delete message;
	delete channel;
	delete user;
}
