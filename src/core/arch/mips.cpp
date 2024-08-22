#include "mips.h"
#include <iostream>

// Генерация кода для MIPS
void MIPSGenerator::generateCode(ASTNode* root) {
    if (!root) return;

    if (root->value == "+") {
        generateBinaryOperationCode("add", "$t1");
    } else if (root->value == "-") {
        generateBinaryOperationCode("sub", "$t1");
    } else if (root->value == "*") {
        generateBinaryOperationCode("mul", "$t1");
    } else if (root->value == "/") {
        generateCode(root->children[0]);
        std::cout << "    addi $sp, $sp, -4" << std::endl;
        std::cout << "    sw $t0, 0($sp)" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    lw $t1, 0($sp)" << std::endl;
        std::cout << "    div $t1, $t0" << std::endl;
        std::cout << "    mflo $t0" << std::endl; // Результат деления помещается в регистр LO
        std::cout << "    addi $sp, $sp, 4" << std::endl;
    } else {
        generateMoveInstruction(root->value);
    }
}

// Генерация кода для бинарных операций
void MIPSGenerator::generateBinaryOperationCode(const std::string& operation, const std::string& reg) {
    generateCode(root->children[0]);
    std::cout << "    addi $sp, $sp, -4" << std::endl;
    std::cout << "    sw $t0, 0($sp)" << std::endl;
    generateCode(root->children[1]);
    std::cout << "    lw " << reg << ", 0($sp)" << std::endl;
    std::cout << "    " << operation << " $t0, " << reg << ", $t0" << std::endl;
    std::cout << "    addi $sp, $sp, 4" << std::endl;
}

// Генерация инструкции li (load immediate)
void MIPSGenerator::generateMoveInstruction(const std::string& value) {
    std::cout << "    li $t0, " << value << std::endl;
}

// Оптимизация кода для MIPS
void MIPSGenerator::optimizeCode(std::string& assemblyCode) {
    std::cout << "Optimizing MIPS assembly code..." << std::endl;

    // Удаление избыточных операций с стеком
    removeRedundantStackOperations(assemblyCode);

    // Применение оптимизаций peephole
    applyPeepholeOptimizations(assemblyCode);
}

// Удаление избыточных операций с стеком
void MIPSGenerator::removeRedundantStackOperations(std::string& assemblyCode) {
    size_t pos;
    while ((pos = assemblyCode.find("addi $sp, $sp, -4\nsw $t0, 0($sp)\nlw $t1, 0($sp)\naddi $sp, $sp, 4")) != std::string::npos) {
        assemblyCode.replace(pos, 53, "move $t1, $t0");
    }
}

// Применение оптимизаций peephole
void MIPSGenerator::applyPeepholeOptimizations(std::string& assemblyCode) {
    size_t pos;
    while ((pos = assemblyCode.find("addi $sp, $sp, -4\nsw $t0, 0($sp)\n")) != std::string::npos) {
        assemblyCode.erase(pos, 19);
    }
    while ((pos = assemblyCode.find("li $t0, 0\nadd $t0, $t0, $t1")) != std::string::npos) {
        assemblyCode.replace(pos, 21, "move $t0, $t1");
    }
}
