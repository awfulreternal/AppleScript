#include "as_telegram.h"
#include <curl/curl.h>
#include <json/json.h>
#include <iostream>
#include <sstream>

// Конструктор
TelegramBot::TelegramBot(const std::string& token) 
    : token(token), apiUrl("https://api.telegram.org/bot" + token + "/") {}

// Функция для обработки ответа от cURL
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Выполнение HTTP-запроса
std::string TelegramBot::performRequest(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return readBuffer;
}

// Отправка текстового сообщения
bool TelegramBot::sendMessage(const std::string& chatId, const std::string& message) {
    // Экранирование сообщения для URL
    char* escapedMessage = curl_easy_escape(nullptr, message.c_str(), message.size());
    std::string url = apiUrl + "sendMessage?chat_id=" + chatId + "&text=" + escapedMessage;
    std::string response = performRequest(url);
    curl_free(escapedMessage); // Освобождение ресурсов после использования

    // Парсинг JSON ответа
    Json::Value jsonResponse;
    Json::CharReaderBuilder readerBuilder;
    std::istringstream responseStream(response);
    std::string errs;
    if (!Json::parseFromStream(readerBuilder, responseStream, &jsonResponse, &errs)) {
        std::cerr << "JSON parse error: " << errs << std::endl;
        return false;
    }
    return jsonResponse["ok"].asBool();
}

// Получение обновлений
std::vector<std::string> TelegramBot::getUpdates() {
    std::string url = apiUrl + "getUpdates";
    std::string response = performRequest(url);

    // Парсинг JSON ответа
    Json::Value jsonResponse;
    Json::CharReaderBuilder readerBuilder;
    std::istringstream responseStream(response);
    std::string errs;
    std::vector<std::string> messages;

    if (!Json::parseFromStream(readerBuilder, responseStream, &jsonResponse, &errs)) {
        std::cerr << "JSON parse error: " << errs << std::endl;
        return messages;
    }

    const Json::Value updates = jsonResponse["result"];
    for (const auto& update : updates) {
        if (update.isMember("message") && update["message"].isMember("text")) {
            messages.push_back(update["message"]["text"].asString());
        }
    }

    return messages;
}
