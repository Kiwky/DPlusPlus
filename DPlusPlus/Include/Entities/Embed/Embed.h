#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Globals.h"
#include "Snowflake.h"

#include "Entities/Embed/EmbedAuthor.h"
#include "Entities/Embed/EmbedFooter.h"
#include "Entities/Embed/EmbedImage.h"
#include "Entities/Embed/EmbedProvider.h"
#include "Entities/Embed/EmbedThumbnail.h"
#include "Entities/Embed/EmbedVideo.h"

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
	void ToJson(nJson &j);
	void AddField(const std::string &name, const std::string &value, bool inlineField);

public:
	//Colors color;
	std::string m_Title;
	std::string m_Type;
	std::string m_Description;
	std::string m_Url;
	std::string m_Timestamp;
	EmbedFooter m_Footer;
	EmbedImage m_Image;
	EmbedThumbnail m_Thumbnail;
	EmbedVideo m_Video;
	EmbedProvider m_Provider;
	EmbedAuthor m_Author;
	std::vector<nJson> m_Fields;

};

