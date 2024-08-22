#include "error_handler.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Глобальный экземпляр обработчика ошибок
ErrorHandler g_errorHandler;

// Добавление новой ошибки
void ErrorHandler::addError(ErrorType type, const std::string& message, int line, int column) {
    errors.emplace_back(type, message, line, column);
}

// Вывод всех ошибок
void ErrorHandler::printErrors() const {
    for (const auto& error : errors) {
        std::cerr << formatError(error) << std::endl;
    }
}

// Запись всех ошибок в файл
void ErrorHandler::writeErrorsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& error : errors) {
            file << formatError(error) << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for writing errors." << std::endl;
    }
}

// Проверка наличия ошибок
bool ErrorHandler::hasErrors() const {
    return !errors.empty();
}

// Очистка списка ошибок
void ErrorHandler::clear() {
    errors.clear();
}

// Форматирование сообщения об ошибке
std::string ErrorHandler::formatError(const Error& error) const {
    std::stringstream ss;
    ss << getErrorTypeString(error.type) << " at line "
       << error.line << ", column " << error.column << ": "
       << error.message;
    return ss.str();
}

// Преобразование типа ошибки в строку для вывода
std::string ErrorHandler::getErrorTypeString(ErrorType type) const {
    switch (type) {
        case ErrorType::SYNTAX_ERROR: return "Syntax Error";
        case ErrorType::SEMANTIC_ERROR: return "Semantic Error";
        case ErrorType::RUNTIME_ERROR: return "Runtime Error";
        case ErrorType::WARNING: return "Warning";
        default: return "Unknown Error";
    }
}
