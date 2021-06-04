#include "Member/Member.h"

#include "User/User.h"

Member::Member(const nJson &json) {
	if(json.contains("user"))
		m_User = new User(json["user"]);

	GetJson(json, "nick",			/**/ m_Nick);
	GetJson(json, "joined_at",		/**/ m_JoinedAt);
	GetJson(json, "premium_Since",	/**/ m_PremiumSince);
	GetJson(json, "deaf",			/**/ m_Deaf);
	GetJson(json, "mute",			/**/ m_Mute);
	GetJson(json, "pending",		/**/ m_Pending);
	GetJson(json, "permissions",	/**/ m_Permissions);
}
