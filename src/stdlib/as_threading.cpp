#include "as_threading.h"
#include <iostream>

namespace as {

// Конструктор класса Thread, принимает функцию для выполнения в новом потоке
Thread::Thread(std::function<void()> func) : thread(func), isRunning(false) {}

// Метод для запуска потока
void Thread::start() {
    if (!isRunning) {
        // Запускаем поток и устанавливаем флаг, что поток запущен
        thread = std::thread([this] {
            if (func) {
                func();  // Выполнение переданной функции
            }
        });
        isRunning = true;
    } else {
        std::cerr << "Thread is already running!" << std::endl;
    }
}

// Метод для ожидания завершения потока
void Thread::join() {
    if (isRunning) {
        if (thread.joinable()) {
            thread.join();  // Ожидание завершения потока
        }
        isRunning = false;
    } else {
        std::cerr << "Thread is not running or already joined!" << std::endl;
    }
}

// Метод для проверки, запущен ли поток
bool Thread::isRunning() const {
    return isRunning;
}

} // namespace as
