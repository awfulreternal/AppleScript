#include "oop.h"
#include <iostream>
#include <stdexcept>

// Метод для определения нового класса
void OOP::defineClass(const std::string& className, const std::vector<std::string>& baseClasses) {
    if (classes.find(className) != classes.end()) {
        throw std::runtime_error("Class already exists: " + className);
    }

    // Проверка существования базовых классов
    for (const auto& baseClass : baseClasses) {
        if (!classExists(baseClass)) {
            throw std::runtime_error("Base class does not exist: " + baseClass);
        }
    }

    // Определение нового класса
    ClassInfo newClass;
    newClass.name = className;
    newClass.baseClasses = baseClasses;
    classes[className] = newClass;

    std::cout << "Class defined: " << className << std::endl;
}

// Метод для создания объекта класса
void OOP::createObject(const std::string& className, const std::string& objectName) {
    if (!classExists(className)) {
        throw std::runtime_error("Class does not exist: " + className);
    }

    // Создание объекта (в данной реализации только вывод сообщения)
    std::cout << "Object created: " << objectName << " of class " << className << std::endl;
}

// Метод для получения информации о классе
void OOP::printClassInfo(const std::string& className) const {
    auto it = classes.find(className);
    if (it == classes.end()) {
        throw std::runtime_error("Class does not exist: " + className);
    }

    const ClassInfo& classInfo = it->second;
    std::cout << "Class: " << classInfo.name << std::endl;
    std::cout << "Base classes:";
    for (const auto& baseClass : classInfo.baseClasses) {
        std::cout << " " << baseClass;
    }
    std::cout << std::endl;
}

// Метод для проверки, существует ли класс
bool OOP::classExists(const std::string& className) const {
    return classes.find(className) != classes.end();
}
