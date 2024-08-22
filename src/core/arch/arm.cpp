#include "arm.h"
#include <iostream>

// Генерация кода для ARM
void ARMGenerator::generateCode(ASTNode* root) {
    if (!root) return;

    if (root->value == "+") {
        generateBinaryOperationCode("add", root->children[0], root->children[1]);
    } else if (root->value == "-") {
        generateBinaryOperationCode("sub", root->children[0], root->children[1]);
    } else if (root->value == "*") {
        generateBinaryOperationCode("mul", root->children[0], root->children[1]);
    } else if (root->value == "/") {
        generateCode(root->children[0]);
        std::cout << "    push {r0}" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    pop {r1}" << std::endl;
        std::cout << "    bl __aeabi_idiv" << std::endl;
    } else {
        // Здесь предполагается, что root->value содержит число
        generateMoveInstruction(root->value);
    }
}

// Генерация кода для бинарных операций
void ARMGenerator::generateBinaryOperationCode(const std::string& operation, ASTNode* left, ASTNode* right) {
    generateCode(left);
    std::cout << "    push {r0}" << std::endl;
    generateCode(right);
    std::cout << "    pop {r1}" << std::endl;
    std::cout << "    " << operation << " r0, r0, r1" << std::endl;
}

// Генерация инструкции mov
void ARMGenerator::generateMoveInstruction(const std::string& value) {
    std::cout << "    mov r0, #" << value << std::endl;
}

// Оптимизация кода для ARM
void ARMGenerator::optimizeCode(std::string& assemblyCode) {
    std::cout << "Optimizing ARM assembly code..." << std::endl;

    // Упрощение инструкций
    // Замена "mov r0, #0\nadd r0, r0, r1" на "mov r0, r1"
    size_t pos;
    while ((pos = assemblyCode.find("mov r0, #0\nadd r0, r0, r1")) != std::string::npos) {
        assemblyCode.replace(pos, 26, "mov r0, r1");
    }

    // Удаление ненужных инструкций
    // Например, если "mov r0, r0" встречается, можно убрать эту инструкцию
    while ((pos = assemblyCode.find("mov r0, r0")) != std::string::npos) {
        assemblyCode.erase(pos, 9);
    }

    // Другие примеры оптимизаций
    // Удаление избыточных push/pop инструкций
    while ((pos = assemblyCode.find("push {r0}\npop {r0}")) != std::string::npos) {
        assemblyCode.erase(pos, 15);
    }

    // Удаление избыточных инструкций, таких как "nop"
    while ((pos = assemblyCode.find("nop")) != std::string::npos) {
        assemblyCode.erase(pos, 3);
    }
}
