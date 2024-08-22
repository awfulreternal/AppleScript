#include "x86.h"
#include <iostream>

// Генерация кода для x86
void X86Generator::generateCode(ASTNode* root) {
    if (!root) return;

    if (root->value == "+") {
        generateBinaryOperationCode("add", "ebx");
    } else if (root->value == "-") {
        generateBinaryOperationCode("sub", "ebx");
    } else if (root->value == "*") {
        generateBinaryOperationCode("imul", "ebx");
    } else if (root->value == "/") {
        generateCode(root->children[0]);
        std::cout << "    push eax" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    pop ebx" << std::endl;
        std::cout << "    xor edx, edx" << std::endl; // Очистка регистра остатка
        std::cout << "    idiv ebx" << std::endl;
    } else {
        generateMoveInstruction(root->value);
    }
}

// Генерация кода для бинарных операций
void X86Generator::generateBinaryOperationCode(const std::string& operation, const std::string& reg) {
    generateCode(root->children[0]);
    std::cout << "    push eax" << std::endl;
    generateCode(root->children[1]);
    std::cout << "    pop " << reg << std::endl;
    std::cout << "    " << operation << " eax, " << reg << std::endl;
}

// Генерация инструкции mov
void X86Generator::generateMoveInstruction(const std::string& value) {
    std::cout << "    mov eax, " << value << std::endl;
}

// Оптимизация кода для x86
void X86Generator::optimizeCode(std::string& assemblyCode) {
    std::cout << "Optimizing x86 assembly code..." << std::endl;

    // Удаление лишних push/pop инструкций
    removeRedundantPushPop(assemblyCode);

    // Применение оптимизаций peephole
    applyPeepholeOptimizations(assemblyCode);
}

// Удаление избыточных инструкций push/pop
void X86Generator::removeRedundantPushPop(std::string& assemblyCode) {
    size_t pos;
    while ((pos = assemblyCode.find("push eax\npop eax")) != std::string::npos) {
        assemblyCode.erase(pos, 15); // Удаление лишней пары push/pop
    }
}

// Применение оптимизаций peephole
void X86Generator::applyPeepholeOptimizations(std::string& assemblyCode) {
    size_t pos;
    while ((pos = assemblyCode.find("mov eax, 0")) != std::string::npos) {
        assemblyCode.replace(pos, 11, "xor eax, eax");
    }
    // Дополнительные примеры оптимизаций
    while ((pos = assemblyCode.find("mov eax, 1\nimul eax, eax")) != std::string::npos) {
        assemblyCode.replace(pos, 19, "mov eax, eax");
    }
}
