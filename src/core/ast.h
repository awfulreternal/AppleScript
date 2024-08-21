#ifndef AST_H
#define AST_H

#include <vector>
#include <string>

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
    OperatorNode(const std::string& op, ASTNode* left, ASTNode* right)
        : op(op), left(left), right(right) {}

    ~OperatorNode() override;

    void print(int indent = 0) const override;

    const std::string& getOperator() const { return op; }
    ASTNode* getLeft() const { return left; }
    ASTNode* getRight() const { return right; }

private:
    std::string op;
    ASTNode* left;
    ASTNode* right;
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
    AssignmentNode(const std::string& varName, ASTNode* expr)
        : varName(varName), expr(expr) {}

    ~AssignmentNode() override;

    void print(int indent = 0) const override;

    const std::string& getVariableName() const { return varName; }
    ASTNode* getExpression() const { return expr; }

private:
    std::string varName;
    ASTNode* expr;
};

// Узел для блока кода (набор инструкций)
class BlockNode : public ASTNode {
public:
    void addStatement(ASTNode* statement) { statements.push_back(statement); }

    ~BlockNode() override;

    void print(int indent = 0) const override;

    const std::vector<ASTNode*>& getStatements() const { return statements; }

private:
    std::vector<ASTNode*> statements;
};

#endif // AST_H
