#include "ast.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>

// Реализация для NumberNode
void NumberNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Number: " << value << std::endl;
}

// Реализация для OperatorNode
OperatorNode::~OperatorNode() = default; // Удаление освобождения памяти; умные указатели будут сами управлять этим

void OperatorNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Operator: " << op << std::endl;
    if (left) left->print(indent + 2); // Печать левого дочернего узла с увеличенным отступом
    if (right) right->print(indent + 2); // Печать правого дочернего узла с увеличенным отступом
}

// Реализация для VariableNode
void VariableNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Variable: " << name << std::endl;
}

// Реализация для AssignmentNode
AssignmentNode::~AssignmentNode() = default; // Удаление освобождения памяти; умные указатели будут сами управлять этим

void AssignmentNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Assignment: " << varName << std::endl;
    if (expr) expr->print(indent + 2); // Печать выражения с увеличенным отступом
}

// Реализация для BlockNode
void BlockNode::addStatement(std::unique_ptr<ASTNode> stmt) {
    statements.push_back(std::move(stmt));
}

void BlockNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Block:" << std::endl;
    for (const auto& stmt : statements) {
        if (stmt) stmt->print(indent + 2); // Печать каждого узла блока с увеличенным отступом
    }
}
