#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <unordered_set>
#include <string_view>

/**
 * @enum TokenType
 * @brief Перечисление типов токенов.
 */
enum class TokenType {
    EOF_TOKEN,       ///< Конец файла
    IDENTIFIER,      ///< Идентификатор
    NUMBER,          ///< Число
    OPERATOR,        ///< Оператор
    PUNCTUATION,     ///< Знак препинания
    CLASS,           ///< Ключевое слово "class"
    FUNCTION,        ///< Ключевое слово "function"
    ASYNC,           ///< Ключевое слово "async"
    AWAIT,           ///< Ключевое слово "await"
    IF,              ///< Ключевое слово "if"
    ELSE,            ///< Ключевое слово "else"
    FOR,             ///< Ключевое слово "for"
    WHILE            ///< Ключевое слово "while"
};

/**
 * @struct Token
 * @brief Структура, представляющая токен.
 */
struct Token {
    TokenType type;      ///< Тип токена
    std::string value;   ///< Значение токена

    Token(TokenType type = TokenType::EOF_TOKEN, std::string_view value = "")
        : type(type), value(value) {}
};

/**
 * @class Lexer
 * @brief Класс лексера для обработки исходного кода.
 */
class Lexer {
public:
    /**
     * @brief Конструктор лексера, принимающий имя файла.
     * @param filename Имя файла для чтения исходного кода.
     */
    explicit Lexer(const std::string& filename);

    /**
     * @brief Получение следующего токена из исходного кода.
     * @return Следующий токен.
     */
    Token getNextToken();

private:
    /**
     * @brief Перемещение к следующему символу в исходном коде.
     */
    void advance();

    /**
     * @brief Обработка идентификаторов и ключевых слов.
     * @return Токен, представляющий идентификатор или ключевое слово.
     */
    Token identifier();

    /**
     * @brief Обработка чисел.
     * @return Токен, представляющий число.
     */
    Token number();

    /**
     * @brief Обработка операторов.
     * @return Токен, представляющий оператор.
     */
    Token op();

    /**
     * @brief Обработка знаков препинания.
     * @return Токен, представляющий знак препинания.
     */
    Token punct();

    std::string source;  ///< Исходный код
    size_t currentIndex; ///< Индекс текущего символа
    char currentChar;    ///< Текущий символ

    /**
     * @brief Множество ключевых слов.
     */
    static const std::unordered_set<std::string> KEYWORDS;
};

#endif // LEXER_H
