#include "Entities/User/User.h"

User::User(const Snowflake &id) {
	*this = API_Call("/users/" + id, methods::GET);
}

User::User(const nJson &json) {
	GetJson(json, "id",				/**/ m_Id);
	GetJson(json, "flags",			/**/ m_Flags);
	GetJson(json, "premium_Type",	/**/ m_PremiumType);
	GetJson(json, "bot",			/**/ m_Bot);
	GetJson(json, "system",			/**/ m_System);
	GetJson(json, "mfa_enabled",	/**/ m_MfaEnabled);
	GetJson(json, "verified",		/**/ m_Verified);
	GetJson(json, "flags",			/**/ m_Flags);
	GetJson(json, "email",			/**/ m_Email);
	GetJson(json, "locale",			/**/ m_Locale);
	GetJson(json, "username",		/**/ m_Username);
	GetJson(json, "discriminator",	/**/ m_Discriminator);
	GetJson(json, "avatar",			/**/ m_Avatar);
}
