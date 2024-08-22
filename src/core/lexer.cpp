#include "lexer.h"
#include <fstream>
#include <cctype>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <string_view>

// Определение ключевых слов
const std::unordered_set<std::string> Lexer::KEYWORDS = {
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
    if (++currentIndex < source.length()) {
        currentChar = source[currentIndex];
    } else {
        currentChar = '\0';
    }
}

// Получение следующего токена
Token Lexer::getNextToken() {
    while (currentChar != '\0') {
        if (std::isspace(static_cast<unsigned char>(currentChar))) {
            advance();
            continue;
        }

        if (std::isalpha(static_cast<unsigned char>(currentChar)) || currentChar == '_') {
            return identifier();
        }

        if (std::isdigit(static_cast<unsigned char>(currentChar))) {
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

    return {TokenType::EOF_TOKEN, ""};
}

// Обработка идентификаторов и ключевых слов
Token Lexer::identifier() {
    std::string result;
    while (std::isalnum(static_cast<unsigned char>(currentChar)) || currentChar == '_') {
        result += currentChar;
        advance();
    }

    if (KEYWORDS.find(result) != KEYWORDS.end()) {
        return keywordToken(result);
    }
    
    return {TokenType::IDENTIFIER, result};
}

// Определение токена для ключевых слов
Token Lexer::keywordToken(const std::string& keyword) const {
    if (keyword == "class") return {TokenType::CLASS, keyword};
    if (keyword == "function") return {TokenType::FUNCTION, keyword};
    if (keyword == "async") return {TokenType::ASYNC, keyword};
    if (keyword == "await") return {TokenType::AWAIT, keyword};
    if (keyword == "if") return {TokenType::IF, keyword};
    if (keyword == "else") return {TokenType::ELSE, keyword};
    if (keyword == "for") return {TokenType::FOR, keyword};
    if (keyword == "while") return {TokenType::WHILE, keyword};
    
    std::cerr << "Error: Unexpected keyword: " << keyword << std::endl;
    throw std::runtime_error("Unexpected keyword: " + keyword);
}

// Обработка чисел
Token Lexer::number() {
    std::string result;
    while (std::isdigit(static_cast<unsigned char>(currentChar))) {
        result += currentChar;
        advance();
    }
    return {TokenType::NUMBER, result};
}

// Обработка операторов
Token Lexer::op() {
    char op = currentChar;
    advance();
    return {TokenType::OPERATOR, std::string(1, op)};
}

// Обработка знаков препинания
Token Lexer::punct() {
    char punct = currentChar;
    advance();
    return {TokenType::PUNCTUATION, std::string(1, punct)};
}
