#ifndef ASYNC_H
#define ASYNC_H

#include <future>
#include <vector>
#include <functional>
#include <iostream>
#include <chrono>

// Класс для асинхронной задачи
class AsyncTask {
public:
    // Конструктор для создания асинхронной задачи
    explicit AsyncTask(std::function<void()> task)
        : taskFunction(std::move(task)), taskFuture(std::async(std::launch::async, taskFunction)) {}

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

// Асинхронный обработчик задач
class AsyncHandler {
public:
    // Добавление новой асинхронной задачи
    void addTask(std::function<void()> task) {
        tasks.emplace_back(std::move(task));
    }

    // Запуск всех асинхронных задач
    void runTasks() {
        // Запуск всех задач
        for (auto& task : tasks) {
            task.get();
        }
        tasks.clear();
    }

    // Запуск всех задач и ожидание их завершения
    void runAndWaitTasks() {
        std::vector<std::future<void>> futures;
        for (auto& task : tasks) {
            futures.push_back(std::async(std::launch::async, [task]() { task.get(); }));
        }
        // Ожидание завершения всех задач
        for (auto& future : futures) {
            future.get();
        }
        tasks.clear();
    }

private:
    std::vector<AsyncTask> tasks;
};

// Глобальный экземпляр обработчика асинхронных задач
extern AsyncHandler g_asyncHandler;

namespace Async {
    // Обработка асинхронных задач
    void handleAsync();
}

#endif // ASYNC_H
