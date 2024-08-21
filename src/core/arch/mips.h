#ifndef MIPS_H
#define MIPS_H

#include "parser.h"
#include <string>

// Класс для генерации и оптимизации MIPS-кода
class MIPSGenerator {
public:
    // Генерация MIPS-кода из абстрактного синтаксического дерева
    void generateCode(ASTNode* root);

    // Оптимизация MIPS-кода для улучшения производительности
    void optimizeCode(std::string& assemblyCode);
};

#endif // MIPS_H
