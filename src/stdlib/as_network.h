#ifndef AS_NETWORK_H
#define AS_NETWORK_H

#include <string>

/**
 * @class NetworkClient
 * @brief Класс для работы с сетевыми соединениями, позволяющий подключаться к серверу, отправлять и получать данные.
 */
class NetworkClient {
public:
    /**
     * @brief Подключается к серверу по указанному адресу и порту.
     * @param address Адрес сервера для подключения (IP-адрес или доменное имя).
     * @param port Порт сервера для подключения.
     * @return true, если подключение успешно; false в противном случае.
     */
    bool connect(const std::string& address, int port);

    /**
     * @brief Отправляет данные на сервер.
     * @param data Данные, которые необходимо отправить.
     * @return true, если отправка успешна; false в противном случае.
     */
    bool sendData(const std::string& data);

    /**
     * @brief Получает данные от сервера.
     * @return std::string Данные, полученные от сервера.
     */
    std::string receiveData();

private:
    int sockfd;  ///< Дескриптор сокета
    bool isConnected; ///< Флаг, указывающий, подключен ли клиент
};

#endif // AS_NETWORK_H
