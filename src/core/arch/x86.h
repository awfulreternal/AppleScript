#ifndef X86_H
#define X86_H

#include "parser.h"
#include <string>

class X86Generator {
public:
    void generateCode(ASTNode* root);
    void optimizeCode(std::string& assemblyCode);
};

#endif
