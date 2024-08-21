#include "x86.h"
#include <iostream>

// Генерация кода для x86
void X86Generator::generateCode(ASTNode* root) {
    if (!root) return;

    if (root->value == "+") {
        generateCode(root->children[0]); // Генерация кода для левого операнда
        std::cout << "    push eax" << std::endl;
        generateCode(root->children[1]); // Генерация кода для правого операнда
        std::cout << "    pop ebx" << std::endl;
        std::cout << "    add eax, ebx" << std::endl;
    } else if (root->value == "-") {
        generateCode(root->children[0]);
        std::cout << "    push eax" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    pop ebx" << std::endl;
        std::cout << "    sub eax, ebx" << std::endl;
    } else if (root->value == "*") {
        generateCode(root->children[0]);
        std::cout << "    push eax" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    pop ebx" << std::endl;
        std::cout << "    imul eax, ebx" << std::endl;
    } else if (root->value == "/") {
        generateCode(root->children[0]);
        std::cout << "    push eax" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    pop ebx" << std::endl;
        std::cout << "    xor edx, edx" << std::endl; // Очистка регистра остатка
        std::cout << "    idiv ebx" << std::endl;
    } else {
        std::cout << "    mov eax, " << root->value << std::endl;
    }
}

// Оптимизация кода для x86
void X86Generator::optimizeCode(std::string& assemblyCode) {
    std::cout << "Optimizing x86 assembly code..." << std::endl;

    // Пример простой оптимизации:
    // Удаление лишних push/pop инструкций, если они не используются
    size_t pos;
    while ((pos = assemblyCode.find("push eax\npop eax")) != std::string::npos) {
        assemblyCode.erase(pos, 15); // Удаление лишней пары push/pop
    }

    // Пример более сложной оптимизации:
    // Peephole optimization - замена коротких последовательностей инструкций на более эффективные
    // Например, заменяем "mov eax, 0" на "xor eax, eax"
    while ((pos = assemblyCode.find("mov eax, 0")) != std::string::npos) {
        assemblyCode.replace(pos, 11, "xor eax, eax");
    }
}
