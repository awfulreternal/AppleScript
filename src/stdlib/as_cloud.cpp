#include "as_cloud.h"
#include <iostream>
#include <curl/curl.h>

// Функция для записи данных в строку
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Реализация класса для работы с облачными сервисами
void CloudServiceClient::uploadFile(const std::string& filePath, const std::string& url) {
    std::cout << "Uploading file: " << filePath << " to URL: " << url << std::endl;

    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();

    if (curl) {
        FILE* file = fopen(filePath.c_str(), "rb");
        if (!file) {
            std::cerr << "Failed to open file for uploading" << std::endl;
            return;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, file);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, nullptr);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        fclose(file);
        curl_easy_cleanup(curl);
    }
}

void CloudServiceClient::downloadFile(const std::string& url, const std::string& outputPath) {
    std::cout << "Downloading file from URL: " << url << " to path: " << outputPath << std::endl;

    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    curl = curl_easy_init();

    if (curl) {
        FILE* file = fopen(outputPath.c_str(), "wb");
        if (!file) {
            std::cerr << "Failed to open file for downloading" << std::endl;
            return;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            fwrite(readBuffer.c_str(), sizeof(char), readBuffer.size(), file);
        }

        fclose(file);
        curl_easy_cleanup(curl);
    }
}
