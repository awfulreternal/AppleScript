#ifndef AS_MULTIMEDIA_H
#define AS_MULTIMEDIA_H

#include <string>

class MultimediaProcessor {
public:
    void processImage(const std::string& imagePath);
    void processVideo(const std::string& videoPath);
    void processAudio(const std::string& audioPath);
};

#endif
