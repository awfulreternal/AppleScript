#ifndef CODEGEN_H
#define CODEGEN_H

#include <string>
#include "ast.h"

/**
 * @class CodeGenerator
 * @brief Класс для генерации промежуточного и объектного кода из AST.
 */
class CodeGenerator {
public:
    /**
     * @brief Генерирует промежуточный и объектный код из корня AST.
     * @param root Корневой узел AST.
     */
    void generate(ASTNode* root);

    /**
     * @brief Получает промежуточный код.
     * @return Промежуточный код в виде строки.
     */
    std::string getIR() const;

    /**
     * @brief Получает объектный код.
     * @return Объектный код в виде строки.
     */
    std::string getObjectCode() const;

private:
    std::string irCode;        ///< Промежуточный код.
    std::string objectCode;    ///< Объектный код.

    // Приватные вспомогательные методы для генерации кода.
    std::string generateClassCode(ASTNode* node);
    std::string generateFunctionCode(ASTNode* node);
    std::string generateExpressionCode(ASTNode* node);
};

#endif // CODEGEN_H
