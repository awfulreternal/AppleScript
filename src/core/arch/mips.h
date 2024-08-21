#ifndef MIPS_H
#define MIPS_H

#include "parser.h"
#include <string>

class MIPSGenerator {
public:
    void generateCode(ASTNode* root);
    void optimizeCode(std::string& assemblyCode);
};

#endif
