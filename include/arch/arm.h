#ifndef ARM_H
#define ARM_H

#include "ast.h"
#include <string>

class ARMGenerator {
public:
    // Генерация кода для ARM
    void generateCode(ASTNode* root);

    // Оптимизация кода для ARM
    void optimizeCode(std::string& assemblyCode);

private:
    // Утилитные функции
    void generateBinaryOperationCode(const std::string& operation, ASTNode* left, ASTNode* right);
    void generateMoveInstruction(const std::string& value);
};

#endif // ARM_H
