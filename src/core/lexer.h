#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <unordered_set>

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
    TOKEN_AWAIT,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_FOR,
    TOKEN_WHILE
};

// Структура токена
struct Token {
    TokenType type;  // Тип токена
    std::string value;  // Значение токена

    Token(TokenType type = TOKEN_EOF, const std::string& value = "")
        : type(type), value(value) {}
};

// Класс лексера для обработки исходного кода
class Lexer {
public:
    // Конструктор лексера, принимающий имя файла
    explicit Lexer(const std::string& filename);

    // Получение следующего токена из исходного кода
    Token getNextToken();

private:
    // Перемещение к следующему символу в исходном коде
    void advance();

    // Обработка идентификаторов и ключевых слов
    Token identifier();

    // Обработка чисел
    Token number();

    // Обработка операторов
    Token op();

    // Обработка знаков препинания
    Token punct();

    std::string source;  // Исходный код
    size_t currentIndex;  // Индекс текущего символа
    char currentChar;  // Текущий символ
};

#endif // LEXER_H
