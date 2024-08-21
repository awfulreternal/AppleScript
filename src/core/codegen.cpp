#include "codegen.h"
#include <sstream>

// Приватные вспомогательные функции
std::string CodeGenerator::generateClassCode(ASTNode* node) {
    std::stringstream ss;
    ss << "Class " << node->value << " {";
    for (auto& child : node->children) {
        if (child->type == "Function") {
            ss << "\n  " << generateFunctionCode(child);
        }
    }
    ss << "\n}";
    return ss.str();
}

std::string CodeGenerator::generateFunctionCode(ASTNode* node) {
    std::stringstream ss;
    ss << "Function " << node->value << " {";
    for (auto& child : node->children) {
        ss << "\n  " << generateExpressionCode(child);
    }
    ss << "\n}";
    return ss.str();
}

std::string CodeGenerator::generateExpressionCode(ASTNode* node) {
    std::stringstream ss;
    if (node->type == "Operator") {
        ss << "Op(" << node->value << ")";
    } else if (node->type == "Number") {
        ss << "Num(" << node->value << ")";
    } else if (node->type == "Identifier") {
        ss << "Var(" << node->value << ")";
    } else {
        ss << "UnknownNode(" << node->value << ")";
    }
    return ss.str();
}

void CodeGenerator::generate(ASTNode* root) {
    if (!root) return;

    // Генерация промежуточного кода
    std::stringstream irStream;
    irStream << "START\n";

    if (root->type == "Class") {
        irStream << generateClassCode(root);
    } else if (root->type == "Function") {
        irStream << generateFunctionCode(root);
    } else {
        irStream << generateExpressionCode(root);
    }

    irStream << "\nEND";
    irCode = irStream.str();

    // Пример генерации объектного кода
    objectCode = "OBJ_CODE(" + irCode + ")";
}

std::string CodeGenerator::getIR() {
    return irCode;
}

std::string CodeGenerator::getObjectCode() {
    return objectCode;
}
