#include "as_cloud.h"
#include <iostream>
#include <curl/curl.h>

// Функция для записи данных в строку
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Реализация класса для работы с облачными сервисами

// Метод для загрузки файла на облачный сервер
void CloudServiceClient::uploadFile(const std::string& filePath, const std::string& url) {
    std::cout << "Uploading file: " << filePath << " to URL: " << url << std::endl;

    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize cURL" << std::endl;
        return;
    }

    FILE* file = fopen(filePath.c_str(), "rb");
    if (!file) {
        std::cerr << "Failed to open file: " << filePath << " for uploading" << std::endl;
        curl_easy_cleanup(curl);
        return;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_READDATA, file);
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, nullptr);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "File upload failed: " << curl_easy_strerror(res) << std::endl;
    } else {
        std::cout << "File uploaded successfully to " << url << std::endl;
    }

    fclose(file);
    curl_easy_cleanup(curl);
}

// Метод для скачивания файла с облачного сервера
void CloudServiceClient::downloadFile(const std::string& url, const std::string& outputPath) {
    std::cout << "Downloading file from URL: " << url << " to path: " << outputPath << std::endl;

    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize cURL" << std::endl;
        return;
    }

    FILE* file = fopen(outputPath.c_str(), "wb");
    if (!file) {
        std::cerr << "Failed to open file: " << outputPath << " for downloading" << std::endl;
        curl_easy_cleanup(curl);
        return;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, nullptr);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "File download failed: " << curl_easy_strerror(res) << std::endl;
    } else {
        std::cout << "File downloaded successfully to " << outputPath << std::endl;
    }

    fclose(file);
    curl_easy_cleanup(curl);
}
