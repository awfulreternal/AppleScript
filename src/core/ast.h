#ifndef AST_H
#define AST_H

#include <vector>
#include <string>
#include <memory> // Для использования std::unique_ptr

// Базовый класс для всех узлов AST
class ASTNode {
public:
    virtual ~ASTNode() = default;

    // Виртуальные методы для вывода дерева и других операций
    virtual void print(int indent = 0) const = 0;
};

// Узел для числового литерала
class NumberNode : public ASTNode {
public:
    explicit NumberNode(int value) : value(value) {}

    void print(int indent = 0) const override;

    int getValue() const { return value; }

private:
    int value;
};

// Узел для оператора (например, +, -, *, /)
class OperatorNode : public ASTNode {
public:
    OperatorNode(const std::string& op, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : op(op), left(std::move(left)), right(std::move(right)) {}

    ~OperatorNode() override = default;

    void print(int indent = 0) const override;

    const std::string& getOperator() const { return op; }
    const ASTNode* getLeft() const { return left.get(); }
    const ASTNode* getRight() const { return right.get(); }

private:
    std::string op;
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;
};

// Узел для переменной
class VariableNode : public ASTNode {
public:
    explicit VariableNode(const std::string& name) : name(name) {}

    void print(int indent = 0) const override;

    const std::string& getName() const { return name; }

private:
    std::string name;
};

// Узел для выражения присваивания
class AssignmentNode : public ASTNode {
public:
    AssignmentNode(const std::string& varName, std::unique_ptr<ASTNode> expr)
        : varName(varName), expr(std::move(expr)) {}

    ~AssignmentNode() override = default;

    void print(int indent = 0) const override;

    const std::string& getVariableName() const { return varName; }
    const ASTNode* getExpression() const { return expr.get(); }

private:
    std::string varName;
    std::unique_ptr<ASTNode> expr;
};

// Узел для блока кода (набор инструкций)
class BlockNode : public ASTNode {
public:
    void addStatement(std::unique_ptr<ASTNode> statement) {
        statements.push_back(std::move(statement));
    }

    ~BlockNode() override = default;

    void print(int indent = 0) const override;

    const std::vector<std::unique_ptr<ASTNode>>& getStatements() const { return statements; }

private:
    std::vector<std::unique_ptr<ASTNode>> statements;
};

#endif // AST_H
