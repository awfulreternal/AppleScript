#include <iostream>
#include <memory>
#include "lexer.h"
#include "parser.h"
#include "semantic_analysis.h"
#include "codegen.h"
#include "optimizer.h"
#include "linker.h"
#include "error_handler.h"

// Функция для очистки ресурсов
void cleanup(ASTNode* root) {
    // Очистка дерева AST
    delete root; 
    // Очистка обработчика ошибок
    g_errorHandler.clear(); 
}

int main(int argc, char* argv[]) {
    // Проверка аргументов командной строки
    if (argc < 2) {
        std::cerr << "Usage: applescript <sourcefile>" << std::endl;
        return 1;
    }

    // Лексический анализ
    Lexer lexer(argv[1]);
    if (g_errorHandler.hasErrors()) {
        g_errorHandler.printErrors();
        return 1;
    }

    // Парсинг исходного кода в AST
    Parser parser(lexer);
    ASTNode* root = nullptr;
    try {
        root = parser.parse();
    } catch (const std::exception& e) {
        g_errorHandler.addError(ErrorType::SYNTAX_ERROR, e.what(), 0, 0); // Параметры строки и столбца можно уточнить
        g_errorHandler.printErrors();
        return 1;
    }

    if (g_errorHandler.hasErrors()) {
        g_errorHandler.printErrors();
        cleanup(root);
        return 1;
    }

    // Семантический анализ
    SemanticAnalyzer semanticAnalyzer;
    if (!semanticAnalyzer.analyze(root)) {
        g_errorHandler.printErrors();
        cleanup(root);
        return 1;
    }

    // Генерация промежуточного кода
    CodeGenerator codegen;
    codegen.generate(root);

    // Оптимизация промежуточного кода
    Optimizer optimizer;
    optimizer.optimize(codegen.getIR());

    // Линковка и компиляция в объектный код
    Linker linker;
    try {
        linker.link(codegen.getObjectCode(), "output.o");
    } catch (const std::exception& e) {
        g_errorHandler.addError(ErrorType::RUNTIME_ERROR, e.what(), 0, 0); // Параметры строки и столбца можно уточнить
        g_errorHandler.printErrors();
        cleanup(root);
        return 1;
    }

    if (g_errorHandler.hasErrors()) {
        g_errorHandler.printErrors();
        cleanup(root);
        return 1;
    }

    std::cout << "Compilation finished: output.o" << std::endl;

    // Очистка ресурсов
    cleanup(root);

    return 0;
}
