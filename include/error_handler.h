#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <string>
#include <vector>

/**
 * @enum ErrorType
 * @brief Перечисление типов ошибок.
 */
enum class ErrorType {
    SYNTAX_ERROR,    ///< Синтаксическая ошибка.
    SEMANTIC_ERROR,  ///< Семантическая ошибка.
    RUNTIME_ERROR,   ///< Ошибка выполнения.
    WARNING          ///< Предупреждение.
};

/**
 * @struct Error
 * @brief Структура, представляющая ошибку.
 */
struct Error {
    ErrorType type;        ///< Тип ошибки.
    std::string message;   ///< Сообщение об ошибке.
    int line;              ///< Номер строки, где произошла ошибка.
    int column;            ///< Номер столбца, где произошла ошибка.

    Error(ErrorType t, const std::string& msg, int l, int c)
        : type(t), message(msg), line(l), column(c) {}
};

/**
 * @class ErrorHandler
 * @brief Класс для обработки ошибок.
 */
class ErrorHandler {
public:
    /**
     * @brief Добавление новой ошибки.
     * @param type Тип ошибки.
     * @param message Сообщение об ошибке.
     * @param line Номер строки.
     * @param column Номер столбца.
     */
    void addError(ErrorType type, const std::string& message, int line, int column);

    /**
     * @brief Вывод всех ошибок на стандартный поток ошибок.
     */
    void printErrors() const;

    /**
     * @brief Запись всех ошибок в файл.
     * @param filename Имя файла для записи ошибок.
     */
    void writeErrorsToFile(const std::string& filename) const;

    /**
     * @brief Проверка наличия ошибок.
     * @return true, если ошибки присутствуют; иначе false.
     */
    bool hasErrors() const;

    /**
     * @brief Очистка списка ошибок.
     */
    void clear();

private:
    std::vector<Error> errors; ///< Список ошибок.

    /**
     * @brief Форматирование сообщения об ошибке.
     * @param error Ошибка для форматирования.
     * @return Отформатированное сообщение об ошибке.
     */
    std::string formatError(const Error& error) const;

    /**
     * @brief Преобразование типа ошибки в строку для вывода.
     * @param type Тип ошибки.
     * @return Строковое представление типа ошибки.
     */
    std::string getErrorTypeString(ErrorType type) const;
};

// Глобальный экземпляр обработчика ошибок
extern ErrorHandler g_errorHandler;

#endif // ERROR_HANDLER_H
