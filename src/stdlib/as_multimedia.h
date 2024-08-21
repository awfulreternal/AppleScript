#ifndef AS_MULTIMEDIA_H
#define AS_MULTIMEDIA_H

#include <string>

/**
 * @brief Класс для обработки мультимедийных файлов (изображений, видео и аудио).
 */
class MultimediaProcessor {
public:
    /**
     * @brief Обработка изображения по заданному пути.
     * 
     * @param imagePath Путь к изображению.
     */
    void processImage(const std::string& imagePath);

    /**
     * @brief Обработка видео по заданному пути.
     * 
     * @param videoPath Путь к видеофайлу.
     */
    void processVideo(const std::string& videoPath);

    /**
     * @brief Обработка аудио по заданному пути.
     * 
     * @param audioPath Путь к аудиофайлу.
     */
    void processAudio(const std::string& audioPath);
};

#endif // AS_MULTIMEDIA_H
