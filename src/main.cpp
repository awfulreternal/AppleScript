#include <iostream>
#include <memory>
#include "lexer.h"
#include "parser.h"
#include "semantic_analysis.h"
#include "codegen.h"
#include "optimizer.h"
#include "linker.h"
#include "error_handler.h"
#include "logger.h"  // Добавлен для логирования

// Функция для очистки ресурсов
void cleanup(std::unique_ptr<ASTNode>& root) {
    root.reset();  // Уменьшает вероятность утечек памяти
    g_errorHandler.clear();  // Очистка обработчика ошибок
}

// Функция для проверки и обработки ошибок
bool checkForErrors() {
    if (g_errorHandler.hasErrors()) {
        g_errorHandler.printErrors();
        return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    // Проверка аргументов командной строки
    if (argc < 2) {
        std::cerr << "Usage: applescript <sourcefile>" << std::endl;
        return 1;
    }

    // Установка уровня логирования (например, из аргументов командной строки)
    Logger::setVerbose(true);  // Включение детального логирования для отладки

    // Лексический анализ
    Lexer lexer(argv[1]);
    if (checkForErrors()) return 1;

    // Парсинг исходного кода в AST
    Parser parser(lexer);
    std::unique_ptr<ASTNode> root;
    try {
        root.reset(parser.parse());
    } catch (const std::exception& e) {
        g_errorHandler.addError(ErrorType::SYNTAX_ERROR, e.what(), 0, 0);  // Уточните параметры строки и столбца
        g_errorHandler.printErrors();
        return 1;
    }
    
    if (checkForErrors()) return 1;

    // Семантический анализ
    SemanticAnalyzer semanticAnalyzer;
    if (!semanticAnalyzer.analyze(root.get())) {
        checkForErrors();
        return 1;
    }

    // Генерация промежуточного кода
    CodeGenerator codegen;
    codegen.generate(root);

    // Оптимизация промежуточного кода
    Optimizer optimizer;
    std::string irCode = codegen.getIR();
    optimizer.optimize(irCode);

    // Линковка и компиляция в объектный код
    Linker linker;
    try {
        std::string objectCode = codegen.getObjectCode();
        linker.link(objectCode, "output.o");
    } catch (const std::exception& e) {
        g_errorHandler.addError(ErrorType::RUNTIME_ERROR, e.what(), 0, 0);  // Уточните параметры строки и столбца
        g_errorHandler.printErrors();
        return 1;
    }

    if (checkForErrors()) return 1;

    std::cout << "Compilation finished successfully. Output file: output.o" << std::endl;

    // Очистка ресурсов
    cleanup(root);

    return 0;
}
