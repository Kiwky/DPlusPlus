#include "Entities/Embed/EmbedFooter.h"

void EmbedFooter::ToJson(nJson &j) {
	j = nJson{
		{"text",			m_Text			},
		{"icon_url",		m_IconUrl		},
		{"proxy_icon_url",	m_ProxyIconUrl	}
	};
}
