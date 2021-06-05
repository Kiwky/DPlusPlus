#include "Ready/EventArgs/ReadyEventArgs.h"

ReadyEventArgs::ReadyEventArgs(const nJson &json) {
	m_GatewayVersion = json["v"];
	m_SessionId = json["session_id"];
}
