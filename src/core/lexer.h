#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum TokenType {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_KEYWORD,
    TOKEN_EOF
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string& filename);
    Token getNextToken();

private:
    std::string source;
    size_t currentIndex;
    char currentChar;

    void advance();
    Token identifier();
    Token number();
    Token op();
};

#endif
