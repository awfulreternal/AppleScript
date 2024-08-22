#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <memory>
#include <vector>
#include <string>

// Структура узла абстрактного синтаксического дерева (AST)
class ASTNode {
public:
    std::string value;                // Значение узла (например, идентификатор, литерал и т.д.)
    std::string type;                 // Тип узла (например, "Class", "Function", "Identifier")
    std::vector<std::unique_ptr<ASTNode>> children;   // Дочерние узлы

    // Конструктор с указанием значения и типа узла
    ASTNode(const std::string& val, const std::string& t = "")
        : value(val), type(t) {}

    // Метод для добавления дочернего узла
    void addChild(std::unique_ptr<ASTNode> child) {
        children.push_back(std::move(child));
    }
};

// Класс для парсинга исходного кода
class Parser {
public:
    // Конструктор, принимающий ссылку на лексер
    explicit Parser(Lexer& lexer);

    // Основной метод для парсинга исходного кода
    std::unique_ptr<ASTNode> parse();

private:
    Lexer& lexer;                 // Лексер для получения токенов
    Token currentToken;           // Текущий токен

    // Перейти к следующему токену
    void advance();

    // Методы для парсинга различных конструкций
    std::unique_ptr<ASTNode> expression();        // Парсинг выражений
    std::unique_ptr<ASTNode> term();              // Парсинг терминов
    std::unique_ptr<ASTNode> factor();            // Парсинг факторов
    std::unique_ptr<ASTNode> parseClass();        // Парсинг классов
    std::unique_ptr<ASTNode> parseFunction();     // Парсинг функций
    std::unique_ptr<ASTNode> parseIdentifier();   // Парсинг идентификаторов и других конструкций
    std::unique_ptr<ASTNode> parseAsync();        // Парсинг асинхронных конструкций

    // Метод для обработки ошибок парсинга
    void error(const std::string& message) const;
};

#endif // PARSER_H
