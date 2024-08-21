#ifndef AS_THREADING_H
#define AS_THREADING_H

#include <thread>
#include <functional>

namespace as {

// Класс для многопоточности
class Thread {
public:
    // Конструктор, принимающий функцию для выполнения в потоке
    explicit Thread(std::function<void()> func);

    // Метод для запуска потока
    void start();

    // Метод для ожидания завершения потока
    void join();

    // Метод для проверки, запущен ли поток
    bool isRunning() const;

private:
    std::thread thread;   // Объект потока
    std::function<void()> func;  // Функция, выполняемая в потоке
    bool isRunning;  // Флаг, указывающий, запущен ли поток
};

} // namespace as

#endif // AS_THREADING_H
