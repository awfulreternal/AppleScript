#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <mutex>  // Для потокобезопасности

/**
 * @class Logger
 * @brief Класс для вывода сообщений в лог.
 * 
 * Поддерживает информационные, отладочные и сообщения об ошибках. Отладочные сообщения выводятся
 * только если установлен режим verbose.
 */
class Logger {
public:
    /**
     * @brief Вывод информационного сообщения.
     * @param message Сообщение для вывода.
     */
    static void info(const std::string& message);

    /**
     * @brief Вывод сообщения об ошибке.
     * @param message Сообщение для вывода.
     */
    static void error(const std::string& message);

    /**
     * @brief Вывод отладочного сообщения, если включен режим verbose.
     * @param message Сообщение для вывода.
     */
    static void debug(const std::string& message);

    /**
     * @brief Установка режима verbose.
     * @param verbose Флаг, указывающий, следует ли включить режим verbose.
     */
    static void setVerbose(bool verbose);

private:
    static bool verbose;        ///< Статическая переменная для хранения режима verbose.
    static std::mutex mutex;    ///< Мьютекс для обеспечения потокобезопасности.
};

#endif // LOGGER_H
