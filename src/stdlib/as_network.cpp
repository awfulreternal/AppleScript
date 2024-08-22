#include "as_network.h"
#include <iostream>
#include <cstring>
#include <unistd.h>    // Для close()
#include <arpa/inet.h> // Для socket(), connect(), send(), recv()

bool NetworkClient::connect(const std::string& address, int port) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error: Failed to create socket" << std::endl;
        return false;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, address.c_str(), &serverAddr.sin_addr) <= 0) {
        std::cerr << "Error: Invalid address/Address not supported" << std::endl;
        close(sockfd);
        return false;
    }

    if (::connect(sockfd, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error: Connection failed" << std::endl;
        close(sockfd);
        return false;
    }

    isConnected = true;
    std::cout << "Connected to " << address << " on port " << port << std::endl;
    return true;
}

bool NetworkClient::sendData(const std::string& data) {
    if (!isConnected) {
        std::cerr << "Error: Not connected to any server" << std::endl;
        return false;
    }

    ssize_t sentBytes = send(sockfd, data.c_str(), data.size(), 0);
    if (sentBytes < 0) {
        std::cerr << "Error: Failed to send data" << std::endl;
        return false;
    }

    std::cout << "Sent data: " << data << std::endl;
    return true;
}

std::string NetworkClient::receiveData() {
    if (!isConnected) {
        std::cerr << "Error: Not connected to any server" << std::endl;
        return "";
    }

    char buffer[1024] = {0};
    ssize_t recvBytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (recvBytes < 0) {
        std::cerr << "Error: Failed to receive data" << std::endl;
        return "";
    }

    std::string data(buffer, recvBytes);
    std::cout << "Received data: " << data << std::endl;
    return data;
}
