#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <memory>
#include <vector>
#include <string>

/**
 * @class ASTNode
 * @brief Узел абстрактного синтаксического дерева (AST).
 *
 * Представляет собой узел в абстрактном синтаксическом дереве с поддержкой дочерних узлов.
 */
class ASTNode {
public:
    std::string value;                ///< Значение узла (например, идентификатор, литерал и т.д.)
    std::string type;                 ///< Тип узла (например, "Class", "Function", "Identifier")
    std::vector<std::unique_ptr<ASTNode>> children;   ///< Дочерние узлы

    /**
     * @brief Конструктор с указанием значения и типа узла.
     * @param val Значение узла.
     * @param t Тип узла.
     */
    ASTNode(const std::string& val, const std::string& t = "")
        : value(val), type(t) {}

    /**
     * @brief Метод для добавления дочернего узла.
     * @param child Указатель на дочерний узел.
     */
    void addChild(std::unique_ptr<ASTNode> child) {
        children.push_back(std::move(child));
    }
};

/**
 * @class Parser
 * @brief Класс для парсинга исходного кода.
 *
 * Отвечает за преобразование исходного кода в абстрактное синтаксическое дерево.
 */
class Parser {
public:
    /**
     * @brief Конструктор, принимающий ссылку на лексер.
     * @param lexer Лексер для получения токенов.
     */
    explicit Parser(Lexer& lexer);

    /**
     * @brief Основной метод для парсинга исходного кода.
     * @return Указатель на корень абстрактного синтаксического дерева.
     */
    std::unique_ptr<ASTNode> parse();

private:
    Lexer& lexer;                 ///< Лексер для получения токенов.
    Token currentToken;           ///< Текущий токен.

    /**
     * @brief Перейти к следующему токену.
     */
    void advance();

    // Методы для парсинга различных конструкций.
    std::unique_ptr<ASTNode> expression();        ///< Парсинг выражений.
    std::unique_ptr<ASTNode> term();              ///< Парсинг терминов.
    std::unique_ptr<ASTNode> factor();            ///< Парсинг факторов.
    std::unique_ptr<ASTNode> parseClass();        ///< Парсинг классов.
    std::unique_ptr<ASTNode> parseFunction();     ///< Парсинг функций.
    std::unique_ptr<ASTNode> parseIdentifier();   ///< Парсинг идентификаторов и других конструкций.
    std::unique_ptr<ASTNode> parseAsync();        ///< Парсинг асинхронных конструкций.

    /**
     * @brief Метод для обработки ошибок парсинга.
     * @param message Сообщение об ошибке.
     */
    void error(const std::string& message) const;
};

#endif // PARSER_H
