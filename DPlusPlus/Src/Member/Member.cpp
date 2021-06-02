#include "Member/Member.h"

#include "User/User.h"

Member::Member(const nJson &json) {
	if(json.contains("user"))
		m_user = new User(json["user"]);

	GetJson(json, "nick",			/**/ m_nick);
	GetJson(json, "joined_at",		/**/ m_joinedAt);
	GetJson(json, "premium_since",	/**/ m_premiumSince);
	GetJson(json, "deaf",			/**/ m_deaf);
	GetJson(json, "mute",			/**/ m_mute);
	GetJson(json, "pending",		/**/ m_pending);
	GetJson(json, "permissions",	/**/ m_permissions);
}
