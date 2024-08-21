#ifndef ARM_H
#define ARM_H

#include "parser.h"
#include <string>

// Класс для генерации и оптимизации кода ARM
class ARMGenerator {
public:
    // Генерация кода ARM из AST
    void generateCode(ASTNode* root);

    // Оптимизация кода ARM
    void optimizeCode(std::string& assemblyCode);
};

#endif // ARM_H
