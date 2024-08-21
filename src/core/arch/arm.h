#ifndef ARM_H
#define ARM_H

#include "parser.h"
#include <string>

class ARMGenerator {
public:
    void generateCode(ASTNode* root);
    void optimizeCode(std::string& assemblyCode);
};

#endif
