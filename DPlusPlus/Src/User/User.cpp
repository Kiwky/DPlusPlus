#include "User/User.h"

User::User(const Snowflake &id) {

}

User::User(const nJson &json) {
	GetJson(json, "id",		/**/ m_id);
}
