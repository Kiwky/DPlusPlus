#include "Guild/Guild.h"

#include "Member/Member.h"

Guild::Guild(const Snowflake &id) {
	*this = Guild(API_Call("/guilds/" + id, methods::GET));
}

Guild::Guild(const nJson &json) {
	GetJson(json, "id",								/**/ m_id);
	GetJson(json, "owner_id",						/**/ m_ownerId);
	GetJson(json, "afk_channel_id",					/**/ m_afkChannelId);
	GetJson(json, "widget_channel_id",				/**/ m_widgetChannelId);
	GetJson(json, "application_id",					/**/ m_applicationId);
	GetJson(json, "system_channel_id",				/**/ m_systemChannelId);
	GetJson(json, "rules_channel_id",				/**/ m_rulesChannelId);
	GetJson(json, "public_updates_channel_id",		/**/ m_publicUpdatesChannelId);
	GetJson(json, "afk_timeout",					/**/ m_afkTimeout);
	GetJson(json, "verification_level",				/**/ m_verificationLevel);
	GetJson(json, "default_message_notifications",	/**/ m_defaultMessageNotifications);
	GetJson(json, "explicit_content_filter",		/**/ m_explicitContentFilter);
	GetJson(json, "mfa_level",						/**/ m_mfaLevel);
	GetJson(json, "system_channel_flags",			/**/ m_systemChannelFlags);
	GetJson(json, "member_count",					/**/ m_memberCount);
	GetJson(json, "max_presences",					/**/ m_maxPresences);
	GetJson(json, "max_members",					/**/ m_maxMembers);
	GetJson(json, "premium_tier",					/**/ m_premiumTier);
	GetJson(json, "premium_subscription_count",		/**/ m_premiumSubscriptionCount);
	GetJson(json, "max_video_channel_users",		/**/ m_maxVideoChannelUsers);
	GetJson(json, "afk_timeout",					/**/ m_afkTimeout);
	GetJson(json, "approximate_member_count",		/**/ m_approximateMemberCount);
	GetJson(json, "approximate_presence_count",		/**/ m_approximatePresenceCount);
	GetJson(json, "owner",							/**/ m_owner);
	GetJson(json, "widget_enabled",					/**/ m_widgetEnabled);
	GetJson(json, "large",							/**/ m_large);
	GetJson(json, "unavailable",					/**/ m_unavailable);
	GetJson(json, "name",							/**/ m_name);
	GetJson(json, "icon",							/**/ m_icon);
	GetJson(json, "icon_hash",						/**/ m_iconHash);
	GetJson(json, "splash",							/**/ m_splash);
	GetJson(json, "discovery_splash",				/**/ m_discoverySplash);
	GetJson(json, "permissions",					/**/ m_permissions);
	GetJson(json, "regions",						/**/ m_regions);
	GetJson(json, "joined_at",						/**/ m_joinedAt);
	GetJson(json, "vanity_url_code",				/**/ m_vanityUrlCode);
	GetJson(json, "description",					/**/ m_description);
	GetJson(json, "banner",							/**/ m_banner);
	GetJson(json, "preferred_locale",				/**/ m_preferredLocale);

	//GetJsonVector(data, "channels",					/**/ channels);
	//GetJsonVector(data, "members",					/**/ members);
	//GetJsonVector(data, "emojis",						/**/ emojis);
}

Member Guild::GetMember(const Snowflake &id) {
	return Member(API_Call("/guilds/" + m_id + "/members/" + id, methods::GET));
}
