#include "codegen.h"
#include <sstream>

// Генерация кода для класса
std::string CodeGenerator::generateClassCode(const ASTNode& node) const {
    std::stringstream ss;
    ss << "Class " << node.value << " {\n";
    
    for (const auto& child : node.children) {
        if (child->type == "Function") {
            ss << "  " << generateFunctionCode(*child) << "\n";
        }
    }
    ss << "}";
    return ss.str();
}

// Генерация кода для функции
std::string CodeGenerator::generateFunctionCode(const ASTNode& node) const {
    std::stringstream ss;
    ss << "Function " << node.value << " {\n";
    
    for (const auto& child : node.children) {
        ss << "  " << generateExpressionCode(*child) << "\n";
    }
    ss << "}";
    return ss.str();
}

// Генерация кода для выражения
std::string CodeGenerator::generateExpressionCode(const ASTNode& node) const {
    std::stringstream ss;
    if (node.type == "Operator") {
        ss << "Op(" << node.value << ")";
    } else if (node.type == "Number") {
        ss << "Num(" << node.value << ")";
    } else if (node.type == "Identifier") {
        ss << "Var(" << node.value << ")";
    } else {
        ss << "UnknownNode(" << node.value << ")";
    }
    return ss.str();
}

// Генерация промежуточного и объектного кода
void CodeGenerator::generate(const std::unique_ptr<ASTNode>& root) {
    if (!root) return;

    std::stringstream irStream;
    irStream << "START\n";
    
    if (root->type == "Class") {
        irStream << generateClassCode(*root) << "\n";
    } else if (root->type == "Function") {
        irStream << generateFunctionCode(*root) << "\n";
    } else {
        irStream << generateExpressionCode(*root) << "\n";
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
