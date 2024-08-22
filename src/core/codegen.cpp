#include "codegen.h"
#include <sstream>

// Генерация кода для класса
std::string CodeGenerator::generateClassCode(ASTNode* node) {
    std::stringstream ss;
    ss << "Class " << node->getName() << " {\n";
    
    for (const auto& child : node->getChildren()) {
        if (child->getType() == "Function") {
            ss << "  " << generateFunctionCode(child) << "\n";
        }
    }
    ss << "}";
    return ss.str();
}

// Генерация кода для функции
std::string CodeGenerator::generateFunctionCode(ASTNode* node) {
    std::stringstream ss;
    ss << "Function " << node->getName() << " {\n";
    
    for (const auto& child : node->getChildren()) {
        ss << "  " << generateExpressionCode(child) << "\n";
    }
    ss << "}";
    return ss.str();
}

// Генерация кода для выражения
std::string CodeGenerator::generateExpressionCode(ASTNode* node) {
    std::stringstream ss;
    if (node->getType() == "Operator") {
        ss << "Op(" << node->getValue() << ")";
    } else if (node->getType() == "Number") {
        ss << "Num(" << node->getValue() << ")";
    } else if (node->getType() == "Identifier") {
        ss << "Var(" << node->getValue() << ")";
    } else {
        ss << "UnknownNode(" << node->getValue() << ")";
    }
    return ss.str();
}

// Генерация промежуточного и объектного кода
void CodeGenerator::generate(ASTNode* root) {
    if (!root) return;

    std::stringstream irStream;
    irStream << "START\n";
    
    if (root->getType() == "Class") {
        irStream << generateClassCode(root) << "\n";
    } else if (root->getType() == "Function") {
        irStream << generateFunctionCode(root) << "\n";
    } else {
        irStream << generateExpressionCode(root) << "\n";
    }
    
    irStream << "END";
    irCode = irStream.str();

    // Пример генерации объектного кода (упрощенный)
    objectCode = "OBJ_CODE(\n" + irCode + "\n)";
}

// Получение промежуточного кода
std::string CodeGenerator::getIR() const {
    return irCode;
}

// Получение объектного кода
std::string CodeGenerator::getObjectCode() const {
    return objectCode;
}
