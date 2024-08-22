#ifndef AS_CLOUD_H
#define AS_CLOUD_H

#include <string>

/**
 * @class CloudServiceClient
 * @brief Класс для работы с облачными сервисами, предоставляющий методы для загрузки и скачивания файлов.
 * 
 * Этот класс использует библиотеку cURL для взаимодействия с облачными сервисами. 
 * Он поддерживает загрузку и скачивание файлов через HTTP/HTTPS протоколы.
 */
class CloudServiceClient {
public:
    /**
     * @brief Загружает файл на указанный URL.
     * 
     * Использует HTTP PUT запрос для загрузки файла на сервер. Подходит для отправки файлов на облачные хранилища и серверы.
     * 
     * @param filePath Путь к файлу, который нужно загрузить.
     * @param url URL, куда файл будет загружен.
     */
    void uploadFile(const std::string& filePath, const std::string& url);

    /**
     * @brief Скачивает файл с указанного URL.
     * 
     * Использует HTTP GET запрос для получения файла с сервера. Подходит для загрузки файлов из облачных хранилищ и серверов.
     * 
     * @param url URL, откуда файл будет скачан.
     * @param outputPath Путь, куда будет сохранен скачанный файл.
     */
    void downloadFile(const std::string& url, const std::string& outputPath);
};

#endif // AS_CLOUD_H
