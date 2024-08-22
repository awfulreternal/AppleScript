#include "cli.h"
#include <iostream>
#include <algorithm> // Для std::transform
#include <cctype>    // Для std::tolower

CLI::CLI(int argc, char* argv[])
    : argc(argc), argv(argv), verbose(false), optimize(false) {}

bool CLI::parseArguments() {
    bool hasSourceFile = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        // Приведение аргумента к нижнему регистру
        std::transform(arg.begin(), arg.end(), arg.begin(), ::tolower);

        if (arg == "--verbose") {
            verbose = true;
        } else if (arg == "--optimize") {
            optimize = true;
        } else if (arg == "--help") {
            std::cout << "Usage: applescript [options] <sourcefile>\n";
            std::cout << "Options:\n";
            std::cout << "  --verbose      Enable verbose output\n";
            std::cout << "  --optimize     Enable code optimization\n";
            std::cout << "  --help         Show this help message\n";
            return false;
        } else if (hasValidExtension(arg)) {
            // Проверка, что аргумент является исходным файлом
            sourceFile = arg;
            hasSourceFile = true;
        } else {
            std::cerr << "Unknown argument: " << arg << std::endl;
            return false;
        }
    }

    if (!hasSourceFile) {
        std::cerr << "Error: No source file specified.\n";
        return false;
    }

    return true;
}

std::string CLI::getSourceFile() const {
    return sourceFile;
}

bool CLI::isVerbose() const {
    return verbose;
}

bool CLI::shouldOptimize() const {
    return optimize;
}

bool CLI::hasValidExtension(const std::string& filename) const {
    // Проверка расширения файла. Например, предполагаем, что исходные файлы имеют расширение ".as"
    const std::string extension = ".as";
    if (filename.size() > extension.size() && 
        filename.compare(filename.size() - extension.size(), extension.size(), extension) == 0) {
        return true;
    }
    return false;
}
