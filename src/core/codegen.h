#ifndef CODEGEN_H
#define CODEGEN_H

#include "parser.h"
#include <string>

class CodeGenerator {
public:
    void generate(ASTNode* root);
    std::string getIR();
    std::string getObjectCode();

private:
    std::string irCode;
    std::string objectCode;
};

#endif
