#include "lexer.h"
#include <fstream>
#include <cctype>

Lexer::Lexer(const std::string& filename) {
    std::ifstream file(filename);
    if (file) {
        source.assign((std::istreambuf_iterator<char>(file)),
                      std::istreambuf_iterator<char>());
    }
    currentIndex = 0;
    currentChar = source[currentIndex];
}

void Lexer::advance() {
    currentIndex++;
    if (currentIndex < source.length()) {
        currentChar = source[currentIndex];
    } else {
        currentChar = '\0';
    }
}

Token Lexer::getNextToken() {
    while (currentChar != '\0') {
        if (isspace(currentChar)) {
            advance();
            continue;
        }

        if (isalpha(currentChar)) {
            return identifier();
        }

        if (isdigit(currentChar)) {
            return number();
        }

        return op();
    }

    return {TOKEN_EOF, ""};
}

Token Lexer::identifier() {
    std::string result;
    while (isalnum(currentChar) || currentChar == '_') {
        result += currentChar;
        advance();
    }
    return {TOKEN_IDENTIFIER, result};
}

Token Lexer::number() {
    std::string result;
    while (isdigit(currentChar)) {
        result += currentChar;
        advance();
    }
    return {TOKEN_NUMBER, result};
}

Token Lexer::op() {
    char op = currentChar;
    advance();
    return {TOKEN_OPERATOR, std::string(1, op)};
}
