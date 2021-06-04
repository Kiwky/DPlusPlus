#include "Embed/EmbedImage.h"

void EmbedImage::ToJson(nJson &j) {
	j = nJson{
		{"url",			m_Url		},
		{"proxy_url",	m_ProxyUrl	},
		{"height",		m_height	},
		{"width",		m_Width		}
	};
}
