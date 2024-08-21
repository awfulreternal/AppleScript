#include "arm.h"
#include <iostream>

// Генерация кода для ARM
void ARMGenerator::generateCode(ASTNode* root) {
    if (!root) return;

    if (root->value == "+") {
        generateCode(root->children[0]);
        std::cout << "    push {r0}" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    pop {r1}" << std::endl;
        std::cout << "    add r0, r0, r1" << std::endl;
    } else if (root->value == "-") {
        generateCode(root->children[0]);
        std::cout << "    push {r0}" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    pop {r1}" << std::endl;
        std::cout << "    sub r0, r0, r1" << std::endl;
    } else if (root->value == "*") {
        generateCode(root->children[0]);
        std::cout << "    push {r0}" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    pop {r1}" << std::endl;
        std::cout << "    mul r0, r0, r1" << std::endl;
    } else if (root->value == "/") {
        generateCode(root->children[0]);
        std::cout << "    push {r0}" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    pop {r1}" << std::endl;
        // В ARM нет простой команды деления, поэтому используется функция библиотеки или ассистирующий код
        std::cout << "    bl __aeabi_idiv" << std::endl;
    } else {
        // Здесь предполагается, что root->value содержит число
        std::cout << "    mov r0, #" << root->value << std::endl;
    }
}

// Оптимизация кода для ARM
void ARMGenerator::optimizeCode(std::string& assemblyCode) {
    std::cout << "Optimizing ARM assembly code..." << std::endl;

    // Пример оптимизации: упрощение инструкций
    // Замена последовательности "mov r0, #0\nadd r0, r0, r1" на "mov r0, r1"
    size_t pos;
    while ((pos = assemblyCode.find("mov r0, #0\nadd r0, r0, r1")) != std::string::npos) {
        assemblyCode.replace(pos, 26, "mov r0, r1");
    }

    // Удаление ненужных инструкций
    // Например, если "mov r0, r0" встречается, можно убрать эту инструкцию
    while ((pos = assemblyCode.find("mov r0, r0")) != std::string::npos) {
        assemblyCode.erase(pos, 9);
    }

    // Обратите внимание, что оптимизации должны учитывать контекст и
    // структуру кода для эффективного применения
}
