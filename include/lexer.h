#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <unordered_set>

// Определение типов токенов
enum class TokenType {
    EOF_TOKEN,       // Конец файла
    IDENTIFIER,      // Идентификатор
    NUMBER,          // Число
    OPERATOR,        // Оператор
    PUNCTUATION,     // Знак препинания
    CLASS,           // Ключевое слово "class"
    FUNCTION,        // Ключевое слово "function"
    ASYNC,           // Ключевое слово "async"
    AWAIT,           // Ключевое слово "await"
    IF,              // Ключевое слово "if"
    ELSE,            // Ключевое слово "else"
    FOR,             // Ключевое слово "for"
    WHILE            // Ключевое слово "while"
};

// Структура токена
struct Token {
    TokenType type;  // Тип токена
    std::string value;  // Значение токена

    Token(TokenType type = TokenType::EOF_TOKEN, const std::string& value = "")
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

    // Множество ключевых слов
    static const std::unordered_set<std::string> KEYWORDS;
};

#endif // LEXER_H
