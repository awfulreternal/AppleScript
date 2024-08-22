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

    // Конструктор с указанием значения и типа узла
    ASTNode(const std::string& val, const std::string& t = "") 
        : value(val), type(t) {}

    // Деструктор для очистки памяти, рекурсивно удаляет дочерние узлы
    ~ASTNode() {                    
        for (ASTNode* child : children) {
            delete child;
        }
    }

    // Метод для добавления дочернего узла
    void addChild(ASTNode* child) {
        children.push_back(child);
    }
};

// Класс для парсинга исходного кода
class Parser {
public:
    // Конструктор, принимающий ссылку на лексер
    explicit Parser(Lexer& lexer);

    // Основной метод для парсинга исходного кода
    ASTNode* parse();

private:
    Lexer& lexer;                 // Лексер для получения токенов
    Token currentToken;           // Текущий токен

    // Перейти к следующему токену
    void advance();

    // Методы для парсинга различных конструкций
    ASTNode* expression();        // Парсинг выражений
    ASTNode* term();              // Парсинг терминов
    ASTNode* factor();            // Парсинг факторов
    ASTNode* parseClass();        // Парсинг классов
    ASTNode* parseFunction();     // Парсинг функций
    ASTNode* parseIdentifier();   // Парсинг идентификаторов и других конструкций
    ASTNode* parseAsync();        // Парсинг асинхронных конструкций

    // Метод для обработки ошибок парсинга
    void error(const std::string& message);
};

#endif // PARSER_H
