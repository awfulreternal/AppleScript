#include "ast.h"
#include <iostream>
#include <iomanip>

// Реализация для NumberNode
void NumberNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Number: " << value << std::endl;
}

// Реализация для OperatorNode
OperatorNode::~OperatorNode() {
    delete left;
    delete right;
}

void OperatorNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Operator: " << op << std::endl;
    if (left) left->print(indent + 2);
    if (right) right->print(indent + 2);
}

// Реализация для VariableNode
void VariableNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Variable: " << name << std::endl;
}

// Реализация для AssignmentNode
AssignmentNode::~AssignmentNode() {
    delete expr;
}

void AssignmentNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Assignment: " << varName << std::endl;
    if (expr) expr->print(indent + 2);
}

// Реализация для BlockNode
BlockNode::~BlockNode() {
    for (ASTNode* stmt : statements) {
        delete stmt;
    }
}

void BlockNode::print(int indent) const {
    std::cout << std::setw(indent) << "" << "Block:" << std::endl;
    for (const ASTNode* stmt : statements) {
        if (stmt) stmt->print(indent + 2);
    }
}
