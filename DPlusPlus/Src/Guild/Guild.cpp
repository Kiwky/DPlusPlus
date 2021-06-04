#include "Guild/Guild.h"

#include "Member/Member.h"

Guild::Guild(const Snowflake &id) {
	*this = Guild(API_Call("/guilds/" + id, methods::GET));
}

Guild::Guild(const nJson &json) {
	GetJson(json, "id",								/**/ m_Id);
	GetJson(json, "owner_id",						/**/ m_OwnerId);
	GetJson(json, "afk_channel_id",					/**/ m_AfkChannelId);
	GetJson(json, "widget_channel_id",				/**/ m_WidgetChannelId);
	GetJson(json, "application_id",					/**/ m_ApplicationId);
	GetJson(json, "system_Channel_id",				/**/ m_SystemChannelId);
	GetJson(json, "rules_channel_id",				/**/ m_RulesChannelId);
	GetJson(json, "public_updates_channel_id",		/**/ m_PublicUpdatesChannelId);
	GetJson(json, "afk_timeout",					/**/ m_AfkTimeout);
	GetJson(json, "verification_level",				/**/ m_VerificationLevel);
	GetJson(json, "default_message_notifications",	/**/ m_DefaultMessageNotifications);
	GetJson(json, "explicit_content_filter",		/**/ m_ExplicitContentFilter);
	GetJson(json, "mfa_level",						/**/ m_MfaLevel);
	GetJson(json, "system_Channel_flags",			/**/ m_SystemChannelFlags);
	GetJson(json, "member_count",					/**/ m_MemberCount);
	GetJson(json, "max_presences",					/**/ m_MaxPresences);
	GetJson(json, "max_members",					/**/ m_MaxMembers);
	GetJson(json, "premium_Tier",					/**/ m_PremiumTier);
	GetJson(json, "premium_Subscription_count",		/**/ m_PremiumSubscriptionCount);
	GetJson(json, "max_video_channel_users",		/**/ m_MaxVideoChannelUsers);
	GetJson(json, "afk_timeout",					/**/ m_AfkTimeout);
	GetJson(json, "approximate_member_count",		/**/ m_ApproximateMemberCount);
	GetJson(json, "approximate_presence_count",		/**/ m_ApproximatePresenceCount);
	GetJson(json, "owner",							/**/ m_Owner);
	GetJson(json, "widget_enabled",					/**/ m_WidgetEnabled);
	GetJson(json, "large",							/**/ m_Large);
	GetJson(json, "unavailable",					/**/ m_Unavailable);
	GetJson(json, "name",							/**/ m_Name);
	GetJson(json, "icon",							/**/ m_Icon);
	GetJson(json, "icon_hash",						/**/ m_IconHash);
	GetJson(json, "splash",							/**/ m_Splash);
	GetJson(json, "discovery_splash",				/**/ m_DiscoverySplash);
	GetJson(json, "permissions",					/**/ m_Permissions);
	GetJson(json, "regions",						/**/ m_Regions);
	GetJson(json, "joined_at",						/**/ m_JoinedAt);
	GetJson(json, "vanity_url_code",				/**/ m_VanityUrlCode);
	GetJson(json, "description",					/**/ m_Description);
	GetJson(json, "banner",							/**/ m_Banner);
	GetJson(json, "preferred_locale",				/**/ m_PreferredLocale);

	//GetJsonVector(data, "channels",					/**/ channels);
	//GetJsonVector(data, "members",					/**/ members);
	//GetJsonVector(data, "emojis",						/**/ emojis);
}

Member Guild::GetMember(const Snowflake &id) {
	return Member(API_Call("/guilds/" + m_Id + "/members/" + id, methods::GET));
}
