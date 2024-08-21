#ifndef CLI_H
#define CLI_H

#include <string>

class CLI {
public:
    CLI(int argc, char* argv[]);
    bool parseArguments();
    std::string getSourceFile() const;
    bool isVerbose() const;
    bool shouldOptimize() const;

private:
    int argc;
    char** argv;
    std::string sourceFile;
    bool verbose;
    bool optimize;
};

#endif
