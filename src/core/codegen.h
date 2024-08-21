#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"
#include <string>

class CodeGenerator {
public:
    void generate(ASTNode* root);
    std::string getIR();
    std::string getObjectCode();

private:
    std::string generateClassCode(ASTNode* node);
    std::string generateFunctionCode(ASTNode* node);
    std::string generateExpressionCode(ASTNode* node);

    std::string irCode;
    std::string objectCode;
};

#endif // CODEGEN_H
