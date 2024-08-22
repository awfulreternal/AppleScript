#ifndef CODEGEN_H
#define CODEGEN_H

#include <string>
#include <memory>
#include "ast.h"

/**
 * @class CodeGenerator
 * @brief Класс для генерации промежуточного и объектного кода из AST.
 */
class CodeGenerator {
public:
    /**
     * @brief Генерирует промежуточный и объектный код из корня AST.
     * @param root Умный указатель на корневой узел AST.
     */
    void generate(const std::unique_ptr<ASTNode>& root);

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

    /**
     * @brief Генерация кода для класса.
     * @param node Узел AST, представляющий класс.
     * @return Код для класса.
     */
    std::string generateClassCode(const ASTNode& node) const;

    /**
     * @brief Генерация кода для функции.
     * @param node Узел AST, представляющий функцию.
     * @return Код для функции.
     */
    std::string generateFunctionCode(const ASTNode& node) const;

    /**
     * @brief Генерация кода для выражения.
     * @param node Узел AST, представляющий выражение.
     * @return Код для выражения.
     */
    std::string generateExpressionCode(const ASTNode& node) const;

    /**
     * @brief Генерация кода для узла типа "Unknown".
     * @param node Узел AST, представляющий неизвестный тип.
     * @return Код для неизвестного типа.
     */
    std::string generateUnknownNodeCode(const ASTNode& node) const;
};

#endif // CODEGEN_H
