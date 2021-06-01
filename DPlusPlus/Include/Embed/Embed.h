#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"
#include "Snowflake.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

enum EmbeType {
	kRich = 0,
	kImage,
	kVideo,
	kGifv,
	kArticle,
	kLink
};

class Embed {

public:
	//Colors color;
	std::string m_title;
	std::string m_type;
	std::string m_description;
	std::string m_url;
	std::string m_timestamp;
	EmbedFooter m_footer;
	EmbedImage m_image;
	EmbedThumbnail m_thumbnail;
	EmbedVideo m_video;
	EmbedProvider m_provider;
	EmbedAuthor m_author;
	std::vector<nJson> m_fields;

};

