#include "lexer.h"
#include <fstream>
#include <cctype>
#include <unordered_set>
#include <stdexcept>
#include <iterator>
#include <iostream>

// Определение ключевых слов
const std::unordered_set<std::string> KEYWORDS = {
    "class", "function", "async", "await", "if", "else", "for", "while"
};

// Конструктор лексера, принимающий имя файла
Lexer::Lexer(const std::string& filename) : currentIndex(0), currentChar('\0') {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    source.assign((std::istreambuf_iterator<char>(file)),
                  std::istreambuf_iterator<char>());
    if (!source.empty()) {
        currentChar = source[currentIndex];
    }
}

// Перемещение к следующему символу
void Lexer::advance() {
    if (currentIndex < source.length()) {
        ++currentIndex;
        if (currentIndex < source.length()) {
            currentChar = source[currentIndex];
        } else {
            currentChar = '\0';
        }
    } else {
        currentChar = '\0';
    }
}

// Получение следующего токена
Token Lexer::getNextToken() {
    while (currentChar != '\0') {
        if (isspace(currentChar)) {
            advance();
            continue;
        }

        if (isalpha(currentChar) || currentChar == '_') {
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

        std::cerr << "Error: Unknown character: " << currentChar << std::endl;
        throw std::runtime_error("Unknown character: " + std::string(1, currentChar));
    }

    return {TOKEN_EOF, ""};
}

// Обработка идентификаторов и ключевых слов
Token Lexer::identifier() {
    std::string result;
    while (isalnum(currentChar) || currentChar == '_') {
        result += currentChar;
        advance();
    }

    if (KEYWORDS.find(result) != KEYWORDS.end()) {
        return keywordToken(result);
    }
    
    return {TOKEN_IDENTIFIER, result};
}

// Определение токена для ключевых слов
Token Lexer::keywordToken(const std::string& keyword) const {
    if (keyword == "class") return {TOKEN_CLASS, keyword};
    if (keyword == "function") return {TOKEN_FUNCTION, keyword};
    if (keyword == "async") return {TOKEN_ASYNC, keyword};
    if (keyword == "await") return {TOKEN_AWAIT, keyword};
    if (keyword == "if") return {TOKEN_IF, keyword};
    if (keyword == "else") return {TOKEN_ELSE, keyword};
    if (keyword == "for") return {TOKEN_FOR, keyword};
    if (keyword == "while") return {TOKEN_WHILE, keyword};
    
    std::cerr << "Error: Unexpected keyword: " << keyword << std::endl;
    throw std::runtime_error("Unexpected keyword: " + keyword);
}

// Обработка чисел
Token Lexer::number() {
    std::string result;
    while (isdigit(currentChar)) {
        result += currentChar;
        advance();
    }
    return {TOKEN_NUMBER, result};
}

// Обработка операторов
Token Lexer::op() {
    char op = currentChar;
    advance();
    return {TOKEN_OPERATOR, std::string(1, op)};
}

// Обработка знаков препинания
Token Lexer::punct() {
    char punct = currentChar;
    advance();
    return {TOKEN_PUNCTUATION, std::string(1, punct)};
}
