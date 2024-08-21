#ifndef AS_CLOUD_H
#define AS_CLOUD_H

#include <string>

/**
 * @class CloudServiceClient
 * @brief Класс для работы с облачными сервисами, позволяющий загружать и скачивать файлы.
 */
class CloudServiceClient {
public:
    /**
     * @brief Загружает файл на указанный URL.
     * @param filePath Путь к файлу, который нужно загрузить.
     * @param url URL, куда файл будет загружен.
     */
    void uploadFile(const std::string& filePath, const std::string& url);

    /**
     * @brief Скачивает файл с указанного URL.
     * @param url URL, откуда файл будет скачан.
     * @param outputPath Путь, куда будет сохранен скачанный файл.
     */
    void downloadFile(const std::string& url, const std::string& outputPath);
};

#endif // AS_CLOUD_H
