#ifndef X86_H
#define X86_H

#include "ast.h"
#include <string>

class X86Generator {
public:
    // Генерация кода для x86
    void generateCode(ASTNode* root);

    // Оптимизация кода для x86
    void optimizeCode(std::string& assemblyCode);

private:
    // Утилитные функции для генерации инструкций
    void generateBinaryOperationCode(const std::string& operation, const std::string& reg);
    void generateMoveInstruction(const std::string& value);

    // Оптимизация инструкций
    void removeRedundantPushPop(std::string& assemblyCode);
    void applyPeepholeOptimizations(std::string& assemblyCode);
};

#endif // X86_H
