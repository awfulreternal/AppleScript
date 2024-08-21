#ifndef SEMANTIC_ANALYSIS_H
#define SEMANTIC_ANALYSIS_H

#include "ast.h"
#include <string>
#include <unordered_map>

// Класс для семантического анализа
class SemanticAnalyzer {
public:
    SemanticAnalyzer();

    // Метод для проверки семантики AST
    bool analyze(ASTNode* root);

    // Метод для получения сообщения об ошибке
    std::string getError() const;

private:
    // Метод для проверки корректности узла AST
    bool analyzeNode(ASTNode* node);

    // Таблица символов для хранения информации о переменных
    std::unordered_map<std::string, bool> symbolTable;
    
    // Сообщение об ошибке
    std::string errorMessage;

    // Метод для добавления переменной в таблицу символов
    void addVariable(const std::string& name);

    // Метод для проверки существования переменной
    bool variableExists(const std::string& name) const;

    // Метод для установки сообщения об ошибке
    void setError(const std::string& message);
};

#endif // SEMANTIC_ANALYSIS_H
