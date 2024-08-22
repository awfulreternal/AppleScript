#include "ast.h"
#include <iostream>
#include <iomanip>

// Реализация для NumberNode
void NumberNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Number: " << value << std::endl;
}

// Реализация для OperatorNode
OperatorNode::~OperatorNode() {
    delete left; // Освобождение памяти для левого дочернего узла
    delete right; // Освобождение памяти для правого дочернего узла
}

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
AssignmentNode::~AssignmentNode() {
    delete expr; // Освобождение памяти для выражения
}

void AssignmentNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Assignment: " << varName << std::endl;
    if (expr) expr->print(indent + 2); // Печать выражения с увеличенным отступом
}

// Реализация для BlockNode
BlockNode::~BlockNode() {
    for (ASTNode* stmt : statements) {
        delete stmt; // Освобождение памяти для каждого элемента в блоке
    }
}

void BlockNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Block:" << std::endl;
    for (const ASTNode* stmt : statements) {
        if (stmt) stmt->print(indent + 2); // Печать каждого узла блока с увеличенным отступом
    }
}
