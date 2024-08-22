#include "cli.h"
#include <iostream>
#include <algorithm> // Для std::find_if

CLI::CLI(int argc, char* argv[])
    : argc(argc), argv(argv), verbose(false), optimize(false) {}

bool CLI::parseArguments() {
    bool hasSourceFile = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
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
        } else if (arg.find_last_of('.') != std::string::npos) {
            // Assuming that any argument with a dot is a source file
            sourceFile = arg;
            hasSourceFile = true;
        }
    }

    return hasSourceFile;
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
