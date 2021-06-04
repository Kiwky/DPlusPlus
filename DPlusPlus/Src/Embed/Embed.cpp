#include "Embed/Embed.h"

void Embed::ToJson(nJson &j) {
	nJson jsonFooter, jsonImage, jsonThumbnail, jsonVideo, jsonProvider, jsonAuthor;

	m_Footer.ToJson(jsonFooter);
	m_Image.ToJson(jsonImage);
	m_Thumbnail.ToJson(jsonThumbnail);
	m_Video.ToJson(jsonVideo);
	m_Provider.ToJson(jsonProvider);
	m_Author.ToJson(jsonAuthor);

	j = nJson{
		{"title",		m_Title			},
		{"type",		m_Type			},
		{"description",	m_Description	},
		{"url",			m_Url			},
		{"timestamp",	m_Timestamp		},
		//{"color",		m_Color			},
		{"footer",		jsonFooter		},
		{"image",		jsonImage		},
		{"thumbnail",	jsonThumbnail	},
		{"video",		jsonVideo		},
		{"provider",	jsonProvider	},
		{"author",		jsonAuthor		}
	};

	for(auto iter = m_Fields.begin(); iter != m_Fields.end(); ++iter) {
		j["fields"].push_back(*iter);
	}
}

void Embed::AddField(const std::string &name, const std::string &value, bool inlineField) {
	nJson jsonField;

	jsonField["name"] = name;
	jsonField["value"] = value;
	jsonField["inline"] = inlineField;

	m_Fields.push_back(jsonField);
}
