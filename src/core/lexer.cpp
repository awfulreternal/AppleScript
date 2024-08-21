#include "lexer.h"
#include <fstream>
#include <cctype>
#include <unordered_set>

// Определение ключевых слов
const std::unordered_set<std::string> KEYWORDS = {
    "class", "function", "async", "await", "if", "else", "for", "while"
};

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

        if (currentChar == '+' || currentChar == '-' ||
            currentChar == '*' || currentChar == '/') {
            return op();
        }

        if (currentChar == '{' || currentChar == '}' ||
            currentChar == '(' || currentChar == ')' ||
            currentChar == '[' || currentChar == ']') {
            return punct();
        }

        throw std::runtime_error("Unknown character");
    }

    return {TOKEN_EOF, ""};
}

Token Lexer::identifier() {
    std::string result;
    while (isalnum(currentChar) || currentChar == '_') {
        result += currentChar;
        advance();
    }

    if (KEYWORDS.find(result) != KEYWORDS.end()) {
        if (result == "class") return {TOKEN_CLASS, result};
        if (result == "function") return {TOKEN_FUNCTION, result};
        if (result == "async") return {TOKEN_ASYNC, result};
        if (result == "await") return {TOKEN_AWAIT, result};
        // Добавьте сюда другие ключевые слова, если необходимо
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

Token Lexer::punct() {
    char punct = currentChar;
    advance();
    return {TOKEN_PUNCTUATION, std::string(1, punct)};
}
