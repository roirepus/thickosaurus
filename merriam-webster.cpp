#include "json.hpp"
#include <cstdlib>
#include <curl/curl.h>
#include <iostream>
#include <string>
using json = nlohmann::json;

// data from libcurl
size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                     std::string *s) {
  s->append(static_cast<char *>(contents), size * nmemb);
  return size * nmemb;
}

// definition of word in JSON format
std::string grab_json_definition(const std::string &word,
                                 const std::string &ref) {
  const char *api_key = std::getenv("DICTIONARY_API_KEY");
  if (api_key == nullptr) {
    std::cerr << "Error: API key is not set in environment variables."
              << std::endl;
    return "";
  }

  std::string uri = "https://dictionaryapi.com/api/v3/references/" + ref +
                    "/json/" + word + "?key=" + api_key;
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, uri.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }

  return readBuffer;
}

int main() {
  std::string word = "test";
  std::string ref = "collegiate";

  std::string jdef = grab_json_definition(word, ref);

  // Parse the JSON response
  try {
    auto json_response = json::parse(jdef);

    // parsed json response
    // std::cout << std::setw(4) << json_response << std::endl;

    // get definition
    if (!json_response.empty() && json_response.is_array() &&
        json_response[0].contains("shortdef")) {
      auto definitions = json_response[0]["shortdef"];
      std::cout << "Definitions:" << std::endl;
      for (const auto &def : definitions) {
        std::cout << "- " << def << std::endl;
      }
    } else {
      std::cerr << "No definitions found or unexpected JSON format."
                << std::endl;
    }
  } catch (json::parse_error &e) {
    std::cerr << "JSON parse error: " << e.what() << std::endl;
  }

  return 0;
}
