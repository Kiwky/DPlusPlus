#include "Embed/Embed.h"

void Embed::ToJson(nJson &j) {
	nJson jsonFooter, jsonImage, jsonThumbnail, jsonVideo, jsonProvider, jsonAuthor;

	m_footer.ToJson(jsonFooter);
	m_image.ToJson(jsonImage);
	m_thumbnail.ToJson(jsonThumbnail);
	m_video.ToJson(jsonVideo);
	m_provider.ToJson(jsonProvider);
	m_author.ToJson(jsonAuthor);

	j = nJson{
		{"title",		m_title			},
		{"type",		m_type			},
		{"description",	m_description	},
		{"url",			m_url			},
		{"timestamp",	m_timestamp		},
		//{"color",		m_color			},
		{"footer",		jsonFooter		},
		{"image",		jsonImage		},
		{"thumbnail",	jsonThumbnail	},
		{"video",		jsonVideo		},
		{"provider",	jsonProvider	},
		{"author",		jsonAuthor		}
	};

	for(auto iter = m_fields.begin(); iter != m_fields.end(); ++iter) {
		j["fields"].push_back(*iter);
	}
}

void Embed::AddField(const std::string &name, const std::string &value, bool inlineField) {
	nJson jsonField;

	jsonField["name"] = name;
	jsonField["value"] = value;
	jsonField["inline"] = inlineField;

	m_fields.push_back(jsonField);
}
