#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <vector>
#include <string>

// Структура узла абстрактного синтаксического дерева (AST)
class ASTNode {
public:
    std::string value;                // Значение узла
    std::string type;                 // Тип узла (например, "Class", "Function", "Identifier")
    std::vector<ASTNode*> children;   // Дочерние узлы

    ASTNode(const std::string& val, const std::string& t = "") : value(val), type(t) {}
    ~ASTNode() {                    // Деструктор для очистки памяти
        for (auto child : children) {
            delete child;
        }
    }
};

// Класс для парсинга исходного кода
class Parser {
public:
    Parser(Lexer& lexer);
    ASTNode* parse();

private:
    Lexer& lexer;                 // Лексер для получения токенов
    Token currentToken;           // Текущий токен

    void advance();               // Перейти к следующему токену
    ASTNode* expression();        // Парсинг выражений
    ASTNode* term();              // Парсинг терминов
    ASTNode* factor();            // Парсинг факторов

    // Расширенные методы для поддержки новых конструкций
    ASTNode* parseClass();        // Парсинг классов
    ASTNode* parseFunction();     // Парсинг функций
    ASTNode* parseIdentifier();   // Парсинг идентификаторов и других конструкций
    ASTNode* parseAsync();        // Парсинг асинхронных конструкций
};

#endif // PARSER_H
