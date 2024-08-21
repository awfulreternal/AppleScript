#include "async.h"
#include <iostream>
#include <future>
#include <vector>
#include <functional>

// Класс для асинхронного программирования
class AsyncTask {
public:
    // Конструктор для создания асинхронной задачи
    AsyncTask(std::function<void()> task) 
        : taskFunction(task), taskFuture(std::async(std::launch::async, task)) {}

    // Проверка статуса задачи
    bool isReady() const {
        return taskFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
    }

    // Получение результата задачи (блокирует выполнение, если задача еще не завершена)
    void get() {
        taskFuture.get();
    }

private:
    std::function<void()> taskFunction;
    std::future<void> taskFuture;
};

// Асинхронный обработчик
class AsyncHandler {
public:
    // Добавление новой асинхронной задачи
    void addTask(std::function<void()> task) {
        tasks.emplace_back(task);
    }

    // Запуск всех асинхронных задач
    void runTasks() {
        for (auto& task : tasks) {
            task.get();
        }
        tasks.clear();
    }

private:
    std::vector<AsyncTask> tasks;
};

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
