#include "User/User.h"

User::User(const Snowflake &id) {
	*this = API_Call("/users/" + id, methods::GET);
}

User::User(const nJson &json) {
	GetJson(json, "id",				/**/ m_id);
	GetJson(json, "flags",			/**/ m_flags);
	GetJson(json, "premium_type",	/**/ m_premiumType);
	GetJson(json, "bot",			/**/ m_bot);
	GetJson(json, "system",			/**/ m_system);
	GetJson(json, "mfa_enabled",	/**/ m_mfaEnabled);
	GetJson(json, "verified",		/**/ m_verified);
	GetJson(json, "flags",			/**/ m_flags);
	GetJson(json, "email",			/**/ m_email);
	GetJson(json, "locale",			/**/ m_locale);
	GetJson(json, "username",		/**/ m_username);
	GetJson(json, "discriminator",	/**/ m_discriminator);
	GetJson(json, "avatar",			/**/ m_avatar);
}
