#include "async.h"
#include <iostream>

AsyncHandler::AsyncHandler() : stopRequested(false) {
    // Создаем несколько потоков для выполнения задач
    const size_t numThreads = std::thread::hardware_concurrency(); // Используем количество потоков процессора
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back(&AsyncHandler::workerThread, this);
    }
}

AsyncHandler::~AsyncHandler() {
    stopRequested = true;
    tasksCv.notify_all(); // Уведомляем все рабочие потоки о завершении работы
    for (std::thread& worker : workers) {
        if (worker.joinable()) {
            worker.join(); // Ожидаем завершения работы всех потоков
        }
    }
}

void AsyncHandler::addTask(const std::function<void()>& task) {
    {
        std::lock_guard<std::mutex> lock(tasksMutex);
        tasks.push_back(task);
    }
    tasksCv.notify_one(); // Уведомляем один поток о наличии новой задачи
}

void AsyncHandler::runTasks() {
    {
        std::lock_guard<std::mutex> lock(tasksMutex);
        // Пустая реализация; выполнение задач будет происходить в workerThread
    }
}

void AsyncHandler::workerThread() {
    while (!stopRequested) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(tasksMutex);
            tasksCv.wait(lock, [this] { return stopRequested || !tasks.empty(); });

            if (stopRequested && tasks.empty()) {
                return;
            }

            if (!tasks.empty()) {
                task = tasks.front();
                tasks.erase(tasks.begin());
            }
        }

        if (task) {
            task();
        }
    }
}
