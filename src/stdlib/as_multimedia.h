#ifndef AS_MULTIMEDIA_H
#define AS_MULTIMEDIA_H

#include <string>

/**
 * @class MultimediaProcessor
 * @brief Класс для обработки мультимедийных файлов, включая изображения, видео и аудио.
 */
class MultimediaProcessor {
public:
    /**
     * @brief Обрабатывает изображение по заданному пути.
     * 
     * Эта функция может использовать библиотеку для обработки изображений, такую как OpenCV.
     * Выводит сообщение о начале обработки изображения и проверяет успешность загрузки.
     * 
     * @param imagePath Путь к изображению.
     */
    void processImage(const std::string& imagePath);

    /**
     * @brief Обрабатывает видео по заданному пути.
     * 
     * Эта функция может использовать библиотеку для обработки видео, такую как FFmpeg.
     * Выводит сообщение о начале обработки видео и проверяет успешность открытия файла.
     * 
     * @param videoPath Путь к видеофайлу.
     */
    void processVideo(const std::string& videoPath);

    /**
     * @brief Обрабатывает аудио по заданному пути.
     * 
     * Эта функция может использовать библиотеку для работы с аудио, такую как PortAudio.
     * Выводит сообщение о начале обработки аудио и проверяет успешность открытия файла.
     * 
     * @param audioPath Путь к аудиофайлу.
     */
    void processAudio(const std::string& audioPath);
};

#endif // AS_MULTIMEDIA_H
