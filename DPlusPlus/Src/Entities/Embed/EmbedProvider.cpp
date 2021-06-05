#include "Entities/Embed/EmbedProvider.h"

void EmbedProvider::ToJson(nJson &j) {
	j = nJson{
		{"name",	m_Name	},
		{"url",		m_Url	}
	};
}
