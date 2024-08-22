#include "arm.h"
#include <iostream>

// Генерация кода для ARM
void ARMGenerator::generateCode(ASTNode* root) {
    if (!root) return;

    if (root->type == ASTNodeType::ADD) {
        generateBinaryOperationCode("add", root->children[0], root->children[1]);
    } else if (root->type == ASTNodeType::SUB) {
        generateBinaryOperationCode("sub", root->children[0], root->children[1]);
    } else if (root->type == ASTNodeType::MUL) {
        generateBinaryOperationCode("mul", root->children[0], root->children[1]);
    } else if (root->type == ASTNodeType::DIV) {
        generateCode(root->children[0]);
        generatePushRegister("r0");
        generateCode(root->children[1]);
        generatePopRegister("r1");
        std::cout << "    bl __aeabi_idiv" << std::endl;
    } else if (root->type == ASTNodeType::NUMBER) {
        generateMoveInstruction(root->value);
    } else if (root->type == ASTNodeType::VARIABLE) {
        // Предполагаем, что переменные обрабатываются отдельно
        std::cout << "    ldr r0, =" << root->value << std::endl;
    } else {
        std::cerr << "Error: Unsupported AST node type for code generation." << std::endl;
    }
}

// Генерация кода для бинарных операций
void ARMGenerator::generateBinaryOperationCode(const std::string& operation, ASTNode* left, ASTNode* right) {
    generateCode(left);
    generatePushRegister("r0");
    generateCode(right);
    generatePopRegister("r1");
    std::cout << "    " << operation << " r0, r0, r1" << std::endl;
}

// Генерация инструкции mov
void ARMGenerator::generateMoveInstruction(const std::string& value) {
    std::cout << "    mov r0, #" << value << std::endl;
}

// Генерация инструкции push для регистра
void ARMGenerator::generatePushRegister(const std::string& reg) {
    std::cout << "    push {" << reg << "}" << std::endl;
}

// Генерация инструкции pop для регистра
void ARMGenerator::generatePopRegister(const std::string& reg) {
    std::cout << "    pop {" << reg << "}" << std::endl;
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

    // Удаление избыточных push/pop инструкций
    while ((pos = assemblyCode.find("push {r0}\npop {r0}")) != std::string::npos) {
        assemblyCode.erase(pos, 15);
    }

    // Удаление избыточных инструкций, таких как "nop"
    while ((pos = assemblyCode.find("nop")) != std::string::npos) {
        assemblyCode.erase(pos, 3);
    }
}
