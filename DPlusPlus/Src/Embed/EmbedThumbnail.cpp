#include "Embed/EmbedThumbnail.h"

void EmbedThumbnail::ToJson(nJson &j) {
	j = nJson{
		{"url",			m_url		},
		{"proxy_url",	m_proxyUrl	},
		{"height",		m_height	},
		{"width",		m_width		}
	};
}
