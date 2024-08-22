#ifndef SEMANTIC_ANALYSIS_H
#define SEMANTIC_ANALYSIS_H

#include "ast.h"
#include <string>
#include <unordered_map>

/**
 * Класс для семантического анализа абстрактного синтаксического дерева (AST).
 * Выполняет проверку правильности переменных и других элементов программы.
 */
class SemanticAnalyzer {
public:
    /**
     * Конструктор класса SemanticAnalyzer.
     */
    SemanticAnalyzer();

    /**
     * Выполняет проверку семантики узлов AST.
     * @param root Указатель на корневой узел AST.
     * @return true, если семантический анализ прошел успешно, иначе false.
     */
    bool analyze(ASTNode* root);

    /**
     * Получает сообщение об ошибке, если таковая имелась во время анализа.
     * @return Сообщение об ошибке.
     */
    std::string getError() const;

private:
    /**
     * Проверяет корректность узла AST.
     * @param node Указатель на узел AST.
     * @return true, если узел корректен, иначе false.
     */
    bool analyzeNode(ASTNode* node);

    /**
     * Добавляет переменную в таблицу символов.
     * @param name Имя переменной.
     */
    void addVariable(const std::string& name);

    /**
     * Проверяет, существует ли переменная в таблице символов.
     * @param name Имя переменной.
     * @return true, если переменная существует, иначе false.
     */
    bool variableExists(const std::string& name) const;

    /**
     * Устанавливает сообщение об ошибке.
     * @param message Сообщение об ошибке.
     */
    void setError(const std::string& message);

    // Таблица символов для хранения информации о переменных
    std::unordered_map<std::string, bool> symbolTable;
    
    // Сообщение об ошибке
    std::string errorMessage;
};

#endif // SEMANTIC_ANALYSIS_H
