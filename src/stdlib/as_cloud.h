#ifndef AS_CLOUD_H
#define AS_CLOUD_H

#include <string>

class CloudServiceClient {
public:
    void uploadFile(const std::string& filePath, const std::string& url);
    void downloadFile(const std::string& url, const std::string& outputPath);
};

#endif
