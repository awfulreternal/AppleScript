#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <vector>

class ASTNode {
public:
    std::string value;
    std::vector<ASTNode*> children;

    ASTNode(const std::string& val) : value(val) {}
};

class Parser {
public:
    Parser(Lexer& lexer);
    ASTNode* parse();

private:
    Lexer& lexer;
    Token currentToken;

    void advance();
    ASTNode* expression();
    ASTNode* term();
    ASTNode* factor();
};

#endif
