#include "parser.h"

Parser::Parser(Lexer& lexer) : lexer(lexer) {
    advance();
}

void Parser::advance() {
    currentToken = lexer.getNextToken();
}

ASTNode* Parser::parse() {
    return expression();
}

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

ASTNode* Parser::factor() {
    if (currentToken.type == TOKEN_NUMBER) {
        ASTNode* node = new ASTNode(currentToken.value);
        advance();
        return node;
    }

    // Обработка идентификаторов и других возможных конструкций

    return nullptr;
}
