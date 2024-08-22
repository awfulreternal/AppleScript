#ifndef AS_THREADING_H
#define AS_THREADING_H

#include <thread>
#include <functional>

namespace as {

// Класс для управления многопоточностью
class Thread {
public:
    /**
     * @brief Конструктор класса Thread.
     * 
     * Принимает функцию, которая будет выполняться в новом потоке.
     * 
     * @param func Функция для выполнения в потоке. Должна быть свободной (не-членской) и не принимать аргументов.
     */
    explicit Thread(std::function<void()> func);

    /**
     * @brief Запускает поток для выполнения функции.
     * 
     * Если поток уже запущен, функция ничего не делает.
     */
    void start();

    /**
     * @brief Ожидает завершения потока.
     * 
     * Если поток уже завершен или не был запущен, функция ничего не делает.
     */
    void join();

    /**
     * @brief Проверяет, запущен ли поток.
     * 
     * @return true Если поток запущен.
     * @return false Если поток не запущен.
     */
    bool isRunning() const;

private:
    std::thread thread;   ///< Объект потока, выполняющий функцию.
    std::function<void()> func;  ///< Функция, выполняемая в потоке.
    bool running;  ///< Флаг, указывающий, запущен ли поток.
};

} // namespace as

#endif // AS_THREADING_H
