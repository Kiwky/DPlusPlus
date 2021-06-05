#include "Entities/Embed/EmbedAuthor.h"

void EmbedAuthor::ToJson(nJson &j) {
	j = nJson{
		{"name",			m_Name			},
		{"url",				m_Url			},
		{"icon_url",		m_IconUrl		},
		{"proxy_icon_url",	m_ProxyIconUrl	}
	};
}
