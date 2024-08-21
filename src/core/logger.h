#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    static void info(const std::string& message);
    static void error(const std::string& message);
    static void debug(const std::string& message);
    static void setVerbose(bool verbose);

private:
    static bool verbose;
};

#endif
