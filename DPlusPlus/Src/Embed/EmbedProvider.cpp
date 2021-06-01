#include "Embed/EmbedProvider.h"

void EmbedProvider::ToJson(nJson &j) {
	j = nJson{
		{"name",	m_name	},
		{"url",		m_url	}
	};
}
