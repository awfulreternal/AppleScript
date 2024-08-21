#ifndef AS_NETWORK_H
#define AS_NETWORK_H

#include <string>

class NetworkClient {
public:
    void connect(const std::string& address);
    void sendData(const std::string& data);
    std::string receiveData();
};

#endif
