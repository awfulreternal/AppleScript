#include "parser.h"

Parser::Parser(Lexer& lexer) : lexer(lexer) {
    advance();
}

void Parser::advance() {
    currentToken = lexer.getNextToken();
}

ASTNode* Parser::parse() {
    ASTNode* node = nullptr;

    if (currentToken.type == TOKEN_CLASS) {
        node = parseClass();
    } else if (currentToken.type == TOKEN_FUNCTION) {
        node = parseFunction();
    } else {
        node = expression();
    }

    return node;
}

// Парсинг класса
ASTNode* Parser::parseClass() {
    ASTNode* classNode = new ASTNode("Class");
    advance(); // Пропускаем ключевое слово 'class'
    
    if (currentToken.type != TOKEN_IDENTIFIER) {
        throw std::runtime_error("Expected class name");
    }
    
    classNode->value = currentToken.value;
    advance(); // Пропускаем имя класса

    if (currentToken.type != TOKEN_LBRACE) {
        throw std::runtime_error("Expected '{'");
    }
    
    advance(); // Пропускаем '{'
    
    while (currentToken.type != TOKEN_RBRACE) {
        if (currentToken.type == TOKEN_FUNCTION) {
            classNode->children.push_back(parseFunction());
        } else {
            throw std::runtime_error("Expected function in class");
        }
    }

    advance(); // Пропускаем '}'
    return classNode;
}

// Парсинг функции
ASTNode* Parser::parseFunction() {
    ASTNode* funcNode = new ASTNode("Function");
    advance(); // Пропускаем ключевое слово 'function'
    
    if (currentToken.type != TOKEN_IDENTIFIER) {
        throw std::runtime_error("Expected function name");
    }
    
    funcNode->value = currentToken.value;
    advance(); // Пропускаем имя функции

    if (currentToken.type != TOKEN_LPAREN) {
        throw std::runtime_error("Expected '('");
    }
    
    advance(); // Пропускаем '('

    // Пропускаем параметры функции (упрощенно)
    while (currentToken.type == TOKEN_IDENTIFIER) {
        funcNode->children.push_back(new ASTNode(currentToken.value));
        advance();
    }

    if (currentToken.type != TOKEN_RPAREN) {
        throw std::runtime_error("Expected ')'");
    }
    
    advance(); // Пропускаем ')'

    if (currentToken.type != TOKEN_LBRACE) {
        throw std::runtime_error("Expected '{'");
    }
    
    advance(); // Пропускаем '{'

    // Пропускаем содержимое функции (упрощенно)
    while (currentToken.type != TOKEN_RBRACE) {
        funcNode->children.push_back(statement());
    }

    advance(); // Пропускаем '}'
    return funcNode;
}

// Парсинг выражения
ASTNode* Parser::expression() {
    ASTNode* node = term();

    while (currentToken.type == TOKEN_OPERATOR && (currentToken.value == "+" || currentToken.value == "-")) {
        ASTNode* newNode = new ASTNode(currentToken.value);
        newNode->children.push_back(node);
        advance();
        newNode->children.push_back(term());
        node = newNode;
    }

    return node;
}

// Парсинг терма
ASTNode* Parser::term() {
    ASTNode* node = factor();

    while (currentToken.type == TOKEN_OPERATOR && (currentToken.value == "*" || currentToken.value == "/")) {
        ASTNode* newNode = new ASTNode(currentToken.value);
        newNode->children.push_back(node);
        advance();
        newNode->children.push_back(factor());
        node = newNode;
    }

    return node;
}

// Парсинг фактора
ASTNode* Parser::factor() {
    if (currentToken.type == TOKEN_NUMBER) {
        ASTNode* node = new ASTNode(currentToken.value);
        advance();
        return node;
    }
    
    if (currentToken.type == TOKEN_IDENTIFIER) {
        ASTNode* node = new ASTNode(currentToken.value);
        advance();
        return node;
    }

    if (currentToken.type == TOKEN_LPAREN) {
        advance();
        ASTNode* node = expression();
        if (currentToken.type != TOKEN_RPAREN) {
            throw std::runtime_error("Expected ')'");
        }
        advance();
        return node;
    }

    // Обработка идентификаторов и других возможных конструкций
    return nullptr;
}

// Парсинг оператора (упрощенно)
ASTNode* Parser::statement() {
    // Реализация для парсинга операторов
    return nullptr;
}
