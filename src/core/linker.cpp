#include "linker.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>

// Функция для объединения объектных файлов в один
std::string Linker::mergeObjectCodes(const std::vector<std::string>& objectFiles) {
    std::stringstream mergedCode;
    for (const auto& file : objectFiles) {
        std::ifstream inFile(file);
        if (!inFile) {
            std::cerr << "Error: Could not open object file " << file << std::endl;
            continue;
        }
        std::string line;
        while (std::getline(inFile, line)) {
            mergedCode << line << "\n";
        }
        inFile.close();
    }
    return mergedCode.str();
}

// Функция для разрешения символов (простейшая реализация)
std::string Linker::resolveSymbols(const std::string& code) {
    // Здесь мы могли бы добавлять или изменять символы в коде
    // Для простоты просто возвращаем исходный код
    return code;
}

void Linker::link(const std::vector<std::string>& objectFiles, const std::string& outputFile) {
    // Объединение объектных файлов
    std::string mergedCode = mergeObjectCodes(objectFiles);
    
    // Разрешение символов (пустая реализация для примера)
    std::string resolvedCode = resolveSymbols(mergedCode);
    
    // Запись окончательного объектного кода в файл
    std::ofstream outFile(outputFile);
    if (outFile) {
        outFile << resolvedCode;
        outFile.close();
        std::cout << "Linking completed successfully. Output file: " << outputFile << std::endl;
    } else {
        std::cerr << "Error: Could not write to output file " << outputFile << std::endl;
    }
}
