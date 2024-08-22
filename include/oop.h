#ifndef OOP_H
#define OOP_H

#include <string>
#include <unordered_map>
#include <vector>

/**
 * @class OOP
 * @brief Класс для управления определением классов и созданием объектов.
 *
 * Позволяет определять новые классы, создавать объекты на основе существующих классов
 * и получать информацию о классах.
 */
class OOP {
public:
    /**
     * @brief Определяет новый класс.
     * @param className Имя нового класса.
     * @param baseClasses Список имен базовых классов.
     * @throws std::runtime_error Если класс с таким именем уже существует или один из базовых классов не найден.
     */
    void defineClass(const std::string& className, const std::vector<std::string>& baseClasses = {});

    /**
     * @brief Создает объект класса.
     * @param className Имя класса, на основе которого создается объект.
     * @param objectName Имя создаваемого объекта.
     * @throws std::runtime_error Если класс с указанным именем не существует.
     */
    void createObject(const std::string& className, const std::string& objectName);

    /**
     * @brief Выводит информацию о классе.
     * @param className Имя класса для получения информации.
     * @throws std::runtime_error Если класс с указанным именем не существует.
     */
    void printClassInfo(const std::string& className) const;

private:
    /**
     * @struct ClassInfo
     * @brief Структура для хранения информации о классе.
     */
    struct ClassInfo {
        std::string name;                        ///< Имя класса.
        std::vector<std::string> baseClasses;    ///< Список базовых классов.
        std::unordered_map<std::string, std::string> attributes; ///< Атрибуты класса (имя -> тип).
    };

    std::unordered_map<std::string, ClassInfo> classes; ///< Хранение информации о классах.

    /**
     * @brief Проверяет, существует ли класс.
     * @param className Имя класса.
     * @return true, если класс существует; иначе false.
     */
    bool classExists(const std::string& className) const;
};

#endif // OOP_H
