#include "logger.h"
#include <iostream>

bool Logger::verbose = false;

void Logger::info(const std::string& message) {
    std::cout << "INFO: " << message << std::endl;
}

void Logger::error(const std::string& message) {
    std::cerr << "ERROR: " << message << std::endl;
}

void Logger::debug(const std::string& message) {
    if (verbose) {
        std::cout << "DEBUG: " << message << std::endl;
    }
}

void Logger::setVerbose(bool v) {
    verbose = v;
}
