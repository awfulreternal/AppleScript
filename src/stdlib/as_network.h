#ifndef AS_NETWORK_H
#define AS_NETWORK_H

#include <string>

/**
 * @brief Класс для работы с сетевыми операциями.
 * 
 * Предоставляет методы для подключения к серверу, отправки и получения данных.
 */
class NetworkClient {
public:
    /**
     * @brief Подключение к серверу.
     * 
     * @param address Адрес сервера для подключения.
     */
    void connect(const std::string& address);

    /**
     * @brief Отправка данных на сервер.
     * 
     * @param data Данные, которые необходимо отправить.
     */
    void sendData(const std::string& data);

    /**
     * @brief Получение данных от сервера.
     * 
     * @return std::string Данные, полученные от сервера.
     */
    std::string receiveData();
};

#endif // AS_NETWORK_H
