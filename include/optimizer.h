#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <string>

/**
 * @class Optimizer
 * @brief Класс для оптимизации промежуточного кода.
 *
 * Предоставляет методы для улучшения и упрощения промежуточного кода.
 */
class Optimizer {
public:
    /**
     * @brief Применяет оптимизации к промежуточному коду.
     * @param irCode Ссылка на строку с промежуточным кодом, который будет оптимизирован.
     */
    void optimize(std::string& irCode);
};

#endif // OPTIMIZER_H
