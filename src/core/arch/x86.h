#include "x86.h"
#include <iostream>

// Генерация кода для x86
void X86Generator::generateCode(ASTNode* root) {
    if (!root) return;

    if (root->value == "+") {
        generateCode(root->children[0]); // Генерация кода для левого операнда
        std::cout << "    push eax" << std::endl; // Сохранение результата левого операнда
        generateCode(root->children[1]); // Генерация кода для правого операнда
        std::cout << "    pop ebx" << std::endl;  // Восстановление результата левого операнда в ebx
        std::cout << "    add eax, ebx" << std::endl; // Сложение
    } else if (root->value == "-") {
        generateCode(root->children[0]); // Генерация кода для левого операнда
        std::cout << "    push eax" << std::endl; // Сохранение результата левого операнда
        generateCode(root->children[1]); // Генерация кода для правого операнда
        std::cout << "    pop ebx" << std::endl;  // Восстановление результата левого операнда в ebx
        std::cout << "    sub eax, ebx" << std::endl; // Вычитание
    } else if (root->value == "*") {
        generateCode(root->children[0]); // Генерация кода для левого операнда
        std::cout << "    push eax" << std::endl; // Сохранение результата левого операнда
        generateCode(root->children[1]); // Генерация кода для правого операнда
        std::cout << "    pop ebx" << std::endl;  // Восстановление результата левого операнда в ebx
        std::cout << "    imul eax, ebx" << std::endl; // Умножение
    } else if (root->value == "/") {
        generateCode(root->children[0]); // Генерация кода для левого операнда
        std::cout << "    push eax" << std::endl; // Сохранение результата левого операнда
        generateCode(root->children[1]); // Генерация кода для правого операнда
        std::cout << "    pop ebx" << std::endl;  // Восстановление результата левого операнда в ebx
        std::cout << "    xor edx, edx" << std::endl; // Очистка регистра остатка
        std::cout << "    idiv ebx" << std::endl; // Деление
    } else {
        std::cout << "    mov eax, " << root->value << std::endl; // Установка значения в eax
    }
}

// Оптимизация кода для x86
void X86Generator::optimizeCode(std::string& assemblyCode) {
    std::cout << "Optimizing x86 assembly code..." << std::endl;

    // Удаление лишних инструкций push/pop, если они не используются
    size_t pos;
    while ((pos = assemblyCode.find("push eax\npop eax")) != std::string::npos) {
        assemblyCode.erase(pos, 15); // Удаление пары push/pop
    }

    // Peephole optimization - замена коротких последовательностей инструкций на более эффективные
    // Например, замена "mov eax, 0" на "xor eax, eax"
    while ((pos = assemblyCode.find("mov eax, 0")) != std::string::npos) {
        assemblyCode.replace(pos, 11, "xor eax, eax");
    }
}
