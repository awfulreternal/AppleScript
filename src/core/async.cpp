#include "async.h"

// Глобальный экземпляр обработчика асинхронных задач
AsyncHandler g_asyncHandler;

void Async::handleAsync() {
    // Пример использования асинхронного обработчика
    g_asyncHandler.addTask([]() {
        std::cout << "Starting async task 1" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Имитация работы
        std::cout << "Async task 1 completed" << std::endl;
    });

    g_asyncHandler.addTask([]() {
        std::cout << "Starting async task 2" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Имитация работы
        std::cout << "Async task 2 completed" << std::endl;
    });

    g_asyncHandler.runTasks(); // Запуск всех задач
}
