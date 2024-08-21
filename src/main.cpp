#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "codegen.h"
#include "optimizer.h"
#include "linker.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: applescript <sourcefile>" << std::endl;
        return 1;
    }

    // Лексический анализ
    Lexer lexer(argv[1]);
    Parser parser(lexer);

    // Парсинг исходного кода в AST
    ASTNode* root = parser.parse();

    // Генерация промежуточного кода
    CodeGenerator codegen;
    codegen.generate(root);

    // Оптимизация промежуточного кода
    Optimizer optimizer;
    optimizer.optimize(codegen.getIR());

    // Линковка и компиляция в объектный код
    Linker linker;
    linker.link(codegen.getObjectCode(), "output.o");

    std::cout << "Compilation finished: output.o" << std::endl;

    return 0;
}
