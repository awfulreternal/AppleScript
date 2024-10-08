#include "semantic_analysis.h"
#include <iostream>

// Конструктор
SemanticAnalyzer::SemanticAnalyzer() : errorMessage("") {}

// Метод для проверки семантики узлов AST
bool SemanticAnalyzer::analyze(ASTNode* root) {
    if (!root) {
        setError("AST root is null");
        return false;
    }

    // Запускаем анализ семантики узлов
    return analyzeNode(root);
}

// Метод для проверки корректности узла AST
bool SemanticAnalyzer::analyzeNode(ASTNode* node) {
    if (!node) return true;

    // Проверяем тип узла и выполняем соответствующие действия
    switch (node->type) {
        case ASTNodeType::ADD:
        case ASTNodeType::SUB:
        case ASTNodeType::MUL:
        case ASTNodeType::DIV:
            // Проверяем, что у узла есть два дочерних узла
            if (node->children.size() != 2) {
                setError("Arithmetic operation requires exactly two operands.");
                return false;
            }
            // Проверяем дочерние узлы
            if (!analyzeNode(node->children[0]) || !analyzeNode(node->children[1])) {
                return false;
            }
            break;

        case ASTNodeType::NUMBER:
            // Числовые узлы не требуют проверки
            break;

        case ASTNodeType::VARIABLE:
            // Проверяем, что переменная существует в таблице символов
            if (!variableExists(node->value)) {
                setError("Undeclared variable: " + node->value);
                return false;
            }
            break;

        case ASTNodeType::CLASS:
        case ASTNodeType::FUNCTION:
            // В реальном анализаторе сюда может быть добавлена проверка на корректность классов и функций
            break;

        default:
            setError("Unknown AST node type: " + node->type);
            return false;
    }

    return true;
}

// Метод для добавления переменной в таблицу символов
void SemanticAnalyzer::addVariable(const std::string& name) {
    symbolTable[name] = true;
}

// Метод для проверки существования переменной
bool SemanticAnalyzer::variableExists(const std::string& name) const {
    return symbolTable.find(name) != symbolTable.end();
}

// Метод для установки сообщения об ошибке
void SemanticAnalyzer::setError(const std::string& message) {
    errorMessage = message;
    std::cerr << "Semantic Error: " << message << std::endl;
}

// Метод для получения сообщения об ошибке
std::string SemanticAnalyzer::getError() const {
    return errorMessage;
}
