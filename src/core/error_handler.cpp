#include <iostream>
#include <vector>
#include <string>

// Определение типов ошибок
enum class ErrorType {
    SYNTAX_ERROR,
    SEMANTIC_ERROR,
    RUNTIME_ERROR,
    WARNING
};

// Структура для представления ошибки
struct Error {
    ErrorType type;
    std::string message;
    int line;
    int column;

    Error(ErrorType type, const std::string &message, int line, int column)
        : type(type), message(message), line(line), column(column) {}
};

// Класс для обработки ошибок
class ErrorHandler {
public:
    // Добавление новой ошибки
    void addError(ErrorType type, const std::string &message, int line, int column) {
        errors.emplace_back(type, message, line, column);
    }

    // Вывод всех ошибок
    void printErrors() const {
        for (const auto &error : errors) {
            std::cerr << getErrorTypeString(error.type) << " at line " 
                      << error.line << ", column " << error.column << ": " 
                      << error.message << std::endl;
        }
    }

    // Проверка наличия ошибок
    bool hasErrors() const {
        return !errors.empty();
    }

    // Очистка списка ошибок
    void clear() {
        errors.clear();
    }

private:
    std::vector<Error> errors;

    // Преобразование типа ошибки в строку для вывода
    std::string getErrorTypeString(ErrorType type) const {
        switch (type) {
            case ErrorType::SYNTAX_ERROR: return "Syntax Error";
            case ErrorType::SEMANTIC_ERROR: return "Semantic Error";
            case ErrorType::RUNTIME_ERROR: return "Runtime Error";
            case ErrorType::WARNING: return "Warning";
            default: return "Unknown Error";
        }
    }
};

// Глобальный экземпляр обработчика ошибок
ErrorHandler g_errorHandler;

