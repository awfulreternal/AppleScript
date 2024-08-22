#ifndef MIPS_H
#define MIPS_H

#include "ast.h"
#include <string>

class MIPSGenerator {
public:
    // Генерация кода для MIPS
    void generateCode(ASTNode* root);

    // Оптимизация кода для MIPS
    void optimizeCode(std::string& assemblyCode);

private:
    // Утилитные функции для генерации инструкций
    void generateBinaryOperationCode(const std::string& operation, ASTNode* left, ASTNode* right);
    void generateMoveInstruction(const std::string& value);

    // Оптимизация инструкций
    void removeRedundantStackOperations(std::string& assemblyCode);
    void applyPeepholeOptimizations(std::string& assemblyCode);
};

#endif // MIPS_H
