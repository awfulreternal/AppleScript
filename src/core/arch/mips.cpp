#include "mips.h"
#include <iostream>

// Генерация кода для MIPS
void MIPSGenerator::generateCode(ASTNode* root) {
    if (!root) return;

    if (root->value == "+") {
        generateCode(root->children[0]);
        std::cout << "    addi $sp, $sp, -4" << std::endl;
        std::cout << "    sw $t0, 0($sp)" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    lw $t1, 0($sp)" << std::endl;
        std::cout << "    add $t0, $t1, $t0" << std::endl;
        std::cout << "    addi $sp, $sp, 4" << std::endl;
    } else if (root->value == "-") {
        generateCode(root->children[0]);
        std::cout << "    addi $sp, $sp, -4" << std::endl;
        std::cout << "    sw $t0, 0($sp)" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    lw $t1, 0($sp)" << std::endl;
        std::cout << "    sub $t0, $t1, $t0" << std::endl;
        std::cout << "    addi $sp, $sp, 4" << std::endl;
    } else if (root->value == "*") {
        generateCode(root->children[0]);
        std::cout << "    addi $sp, $sp, -4" << std::endl;
        std::cout << "    sw $t0, 0($sp)" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    lw $t1, 0($sp)" << std::endl;
        std::cout << "    mul $t0, $t1, $t0" << std::endl;
        std::cout << "    addi $sp, $sp, 4" << std::endl;
    } else if (root->value == "/") {
        generateCode(root->children[0]);
        std::cout << "    addi $sp, $sp, -4" << std::endl;
        std::cout << "    sw $t0, 0($sp)" << std::endl;
        generateCode(root->children[1]);
        std::cout << "    lw $t1, 0($sp)" << std::endl;
        std::cout << "    div $t0, $t1, $t0" << std::endl;
        std::cout << "    mflo $t0" << std::endl; // Результат деления помещается в регистр LO
        std::cout << "    addi $sp, $sp, 4" << std::endl;
    } else {
        std::cout << "    li $t0, " << root->value << std::endl;
    }
}

// Оптимизация кода для MIPS
void MIPSGenerator::optimizeCode(std::string& assemblyCode) {
    std::cout << "Optimizing MIPS assembly code..." << std::endl;

    // Peephole optimization: замена неэффективных инструкций на более эффективные
    size_t pos;
    while ((pos = assemblyCode.find("addi $sp, $sp, -4\nsw $t0, 0($sp)\nlw $t1, 0($sp)\naddi $sp, $sp, 4")) != std::string::npos) {
        assemblyCode.replace(pos, 53, "move $t1, $t0");
    }

    // Dead code elimination - удаление кода, который не влияет на результат
    // Пример простой оптимизации: удаление инструкции, которая не используется
    // (этот фрагмент кода может быть сложнее в зависимости от контекста)
    // Здесь только иллюстративный пример
}
