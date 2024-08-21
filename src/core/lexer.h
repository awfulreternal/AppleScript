#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <unordered_map>

// Определение типов токенов
enum TokenType {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATION,
    TOKEN_CLASS,
    TOKEN_FUNCTION,
    TOKEN_ASYNC,
    TOKEN_AWAIT
};

// Структура токена
struct Token {
    TokenType type;
    std::string value;
};

// Класс лексера
class Lexer {
public:
    Lexer(const std::string& filename);
    Token getNextToken();

private:
    void advance();
    Token identifier();
    Token number();
    Token op();
    Token punct();

    std::string source;
    size_t currentIndex;
    char currentChar;
};

#endif // LEXER_H
