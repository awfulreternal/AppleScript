#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <string>

class Optimizer {
public:
    // Метод для оптимизации промежуточного кода (IR)
    void optimize(std::string& irCode);
};

#endif // OPTIMIZER_H
