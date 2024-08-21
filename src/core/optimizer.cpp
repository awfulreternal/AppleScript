#include "optimizer.h"
#include <algorithm>

void Optimizer::optimize(std::string& irCode) {
    // Пример простой оптимизации - удаление лишних пробелов
    irCode.erase(std::remove(irCode.begin(), irCode.end(), ' '), irCode.end());
}
