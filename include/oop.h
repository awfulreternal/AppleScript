#ifndef OOP_H
#define OOP_H

#include <string>
#include <unordered_map>
#include <vector>

class OOP {
public:
    // Метод для определения нового класса
    void defineClass(const std::string& className, const std::vector<std::string>& baseClasses = {});

    // Метод для создания объекта класса
    void createObject(const std::string& className, const std::string& objectName);

    // Метод для получения информации о классе
    void printClassInfo(const std::string& className) const;

private:
    struct ClassInfo {
        std::string name;
        std::vector<std::string> baseClasses;
        std::unordered_map<std::string, std::string> attributes; // Атрибуты класса (имя -> тип)
    };

    std::unordered_map<std::string, ClassInfo> classes; // Хранение информации о классах

    // Метод для проверки, существует ли класс
    bool classExists(const std::string& className) const;
};

#endif // OOP_H
