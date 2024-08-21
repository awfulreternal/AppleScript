#include "codegen.h"

void CodeGenerator::generate(ASTNode* root) {
    // Пример генерации простого промежуточного кода (IR)
    if (root) {
        irCode = "IR_CODE(" + root->value + ")";
        for (auto child : root->children) {
            irCode += "\nIR_CODE(" + child->value + ")";
        }
    }

    // Пример генерации объектного кода
    objectCode = "OBJ_CODE(" + irCode + ")";
}

std::string CodeGenerator::getIR() {
    return irCode;
}

std::string CodeGenerator::getObjectCode() {
    return objectCode;
}
