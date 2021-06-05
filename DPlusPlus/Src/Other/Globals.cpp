#include "Discord.h"
#include "Other/Globals.h"

std::string GLOBAL_GATEWAY_URL = "wss://gateway.discord.gg/?v=8&encoding=json";
std::string GLOBAL_API_URL = "https://discord.com/api/v8";

namespace DPlusPlus {

nJson API_Call(const std::string &url, method apiMethod, const std::string &jsonObject) {
	try {
		web::json::value jsonValue;
		web::http::client::http_client client(
			web::uri(utility::conversions::to_string_t(GLOBAL_API_URL))
		);
		std::string httpToken = "Bot " + Discord::GetToken();

		http_request req(apiMethod);
		req.set_request_uri(web::uri(utility::conversions::to_string_t(url)));
		req.headers().add(L"Authorization", httpToken.c_str());
		req.headers().add(L"User-Agent", L"DPlusPlus");
		req.headers().add(L"Content-Type", L"application/json");

		if((apiMethod != methods::GET) && (apiMethod != methods::HEAD))
			req.set_body(jsonObject);

		utility::string_t responseString;
		unsigned short code = 0;

		do {
			pplx::task<http_response> requestTask = client.request(req).then([](http_response response) {
				return response;
			});

			requestTask.wait();
			responseString = requestTask.get().extract_string().get();

			code = requestTask.get().status_code();
			if(code == 429) {
				Log::Warning("Spam detected!");
			}
		} while(code == 429);

		nJson s = nJson::parse(responseString.begin(), responseString.end());
		return s;
	} catch(std::exception &e) {
		Log::Error("[API_Call] error: " + std::string(e.what()));
	}
	return "";
}

}