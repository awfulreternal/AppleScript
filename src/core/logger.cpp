#include "logger.h"
#include <iostream>
#include <mutex>

// Инициализация статических членов
bool Logger::verbose = false;
std::mutex Logger::mutex;

// Вывод информационного сообщения
void Logger::info(const std::string& message) {
    std::cout << "INFO: " << message << std::endl;
}

// Вывод сообщения об ошибке
void Logger::error(const std::string& message) {
    std::cerr << "ERROR: " << message << std::endl;
}

// Вывод отладочного сообщения, если включен режим verbose
void Logger::debug(const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex);  // Защита доступа к переменной verbose
    if (verbose) {
        std::cout << "DEBUG: " << message << std::endl;
    }
}

// Установка режима verbose
void Logger::setVerbose(bool v) {
    std::lock_guard<std::mutex> lock(mutex);  // Защита доступа к переменной verbose
    verbose = v;
}
