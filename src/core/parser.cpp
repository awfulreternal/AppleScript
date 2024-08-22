#include "parser.h"
#include <stdexcept>
#include <sstream>

// Конструктор, инициализирующий лексер и устанавливающий первый токен
Parser::Parser(Lexer& lexer) : lexer(lexer) {
    advance();
}

// Продвигает токен к следующему
void Parser::advance() {
    currentToken = lexer.getNextToken();
}

// Основной метод для парсинга
std::unique_ptr<ASTNode> Parser::parse() {
    switch (currentToken.type) {
        case TOKEN_CLASS: return parseClass();
        case TOKEN_FUNCTION: return parseFunction();
        // Добавлены возможности для других типов
        case TOKEN_IDENTIFIER: return parseIdentifier();
        case TOKEN_ASYNC: return parseAsync();
        default: return expression();
    }
}

// Парсинг класса
std::unique_ptr<ASTNode> Parser::parseClass() {
    advance(); // Пропускаем ключевое слово 'class'

    if (currentToken.type != TOKEN_IDENTIFIER) {
        error("Expected class name");
    }

    auto classNode = std::make_unique<ASTNode>(currentToken.value, "Class");
    advance(); // Пропускаем имя класса

    if (currentToken.type != TOKEN_LBRACE) {
        error("Expected '{'");
    }
    advance(); // Пропускаем '{'

    while (currentToken.type != TOKEN_RBRACE) {
        if (currentToken.type == TOKEN_FUNCTION) {
            classNode->addChild(parseFunction());
        } else {
            error("Expected function or '}' in class");
        }
    }
    advance(); // Пропускаем '}'

    return classNode;
}

// Парсинг функции
std::unique_ptr<ASTNode> Parser::parseFunction() {
    advance(); // Пропускаем ключевое слово 'function'

    if (currentToken.type != TOKEN_IDENTIFIER) {
        error("Expected function name");
    }

    auto funcNode = std::make_unique<ASTNode>(currentToken.value, "Function");
    advance(); // Пропускаем имя функции

    if (currentToken.type != TOKEN_LPAREN) {
        error("Expected '('");
    }
    advance(); // Пропускаем '('

    // Пропускаем параметры функции (упрощенно)
    while (currentToken.type == TOKEN_IDENTIFIER) {
        funcNode->addChild(std::make_unique<ASTNode>(currentToken.value, "Parameter"));
        advance();
    }

    if (currentToken.type != TOKEN_RPAREN) {
        error("Expected ')'");
    }
    advance(); // Пропускаем ')'

    if (currentToken.type != TOKEN_LBRACE) {
        error("Expected '{'");
    }
    advance(); // Пропускаем '{'

    // Пропускаем содержимое функции (упрощенно)
    while (currentToken.type != TOKEN_RBRACE) {
        funcNode->addChild(statement());
    }
    advance(); // Пропускаем '}'

    return funcNode;
}

// Парсинг выражения
std::unique_ptr<ASTNode> Parser::expression() {
    auto node = term();

    while (currentToken.type == TOKEN_OPERATOR && 
           (currentToken.value == "+" || currentToken.value == "-")) {
        auto newNode = std::make_unique<ASTNode>(currentToken.value, "Operator");
        newNode->addChild(std::move(node));
        advance();
        newNode->addChild(term());
        node = std::move(newNode);
    }

    return node;
}

// Парсинг терма
std::unique_ptr<ASTNode> Parser::term() {
    auto node = factor();

    while (currentToken.type == TOKEN_OPERATOR && 
           (currentToken.value == "*" || currentToken.value == "/")) {
        auto newNode = std::make_unique<ASTNode>(currentToken.value, "Operator");
        newNode->addChild(std::move(node));
        advance();
        newNode->addChild(factor());
        node = std::move(newNode);
    }

    return node;
}

// Парсинг фактора
std::unique_ptr<ASTNode> Parser::factor() {
    if (currentToken.type == TOKEN_NUMBER || currentToken.type == TOKEN_IDENTIFIER) {
        auto node = std::make_unique<ASTNode>(currentToken.value, currentToken.type == TOKEN_NUMBER ? "Number" : "Identifier");
        advance();
        return node;
    }

    if (currentToken.type == TOKEN_LPAREN) {
        advance();
        auto node = expression();
        if (currentToken.type != TOKEN_RPAREN) {
            error("Expected ')'");
        }
        advance();
        return node;
    }

    error("Unexpected token in factor");
    return nullptr; // Возврат nullptr для предотвращения предупреждений компилятора
}

// Парсинг оператора (упрощенно)
std::unique_ptr<ASTNode> Parser::statement() {
    // Реализация для парсинга операторов
    throw std::runtime_error("Statement parsing not implemented");
}

// Метод для обработки ошибок парсинга
void Parser::error(const std::string& message) const {
    std::ostringstream oss;
    oss << "Error: " << message << " at token '" << currentToken.value << "'";
    throw std::runtime_error(oss.str());
}
