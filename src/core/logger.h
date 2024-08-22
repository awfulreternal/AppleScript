#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <mutex>  // Для потокобезопасности

class Logger {
public:
    // Вывод информационного сообщения
    static void info(const std::string& message);

    // Вывод сообщения об ошибке
    static void error(const std::string& message);

    // Вывод отладочного сообщения, если включен режим verbose
    static void debug(const std::string& message);

    // Установка режима verbose
    static void setVerbose(bool verbose);

private:
    // Статическая переменная для хранения режима verbose
    static bool verbose;

    // Мьютекс для обеспечения потокобезопасности
    static std::mutex mutex;
};

#endif // LOGGER_H
