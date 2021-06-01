#include "Embed/EmbedAuthor.h"

void EmbedAuthor::ToJson(nJson &j) {
	j = nJson{
		{"name",			m_name			},
		{"url",				m_url			},
		{"icon_url",		m_iconUrl		},
		{"proxy_icon_url",	m_proxyIconUrl	}
	};
}
