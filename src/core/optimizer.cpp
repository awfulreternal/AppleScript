#include "optimizer.h"
#include <algorithm>
#include <sstream>
#include <iostream>

// Утилитная функция для удаления лишних пробелов
std::string removeSpaces(const std::string& code) {
    std::string result;
    std::remove_copy_if(code.begin(), code.end(), std::back_inserter(result), ::isspace);
    return result;
}

// Утилитная функция для удаления мертвого кода (упрощенная версия)
std::string removeDeadCode(const std::string& code) {
    std::stringstream ss(code);
    std::string line;
    std::string result;
    bool isDeadCode = false;

    // Простейший пример удаления мертвого кода: удаляем строки, начинающиеся с "/*"
    while (std::getline(ss, line)) {
        if (line.find("/*") != std::string::npos) {
            isDeadCode = true;
        }
        if (line.find("*/") != std::string::npos) {
            isDeadCode = false;
            continue;
        }
        if (!isDeadCode) {
            result += line + "\n";
        }
    }

    return result;
}

void Optimizer::optimize(std::string& irCode) {
    // Применение оптимизации: удаление лишних пробелов
    irCode = removeSpaces(irCode);

    // Применение оптимизации: удаление мертвого кода
    irCode = removeDeadCode(irCode);

    // Дополнительные оптимизации могут быть добавлены здесь
    std::cout << "Optimizations applied successfully." << std::endl;
}
