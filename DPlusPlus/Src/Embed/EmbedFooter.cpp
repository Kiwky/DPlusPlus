#include "Embed/EmbedFooter.h"

void EmbedFooter::ToJson(nJson &j) {
	j = nJson{
		{"text",			m_text			},
		{"icon_url",		m_iconUrl		},
		{"proxy_icon_url",	m_proxyIconUrl	}
	};
}
