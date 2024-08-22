#include "linker.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

// Функция для объединения объектных файлов в один
std::string Linker::mergeObjectCodes(const std::vector<std::string>& objectFiles) const {
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
    }
    
    return mergedCode.str();
}

// Функция для разрешения символов (пустая реализация, может быть расширена)
std::string Linker::resolveSymbols(const std::string& code) const {
    // Здесь можно добавить логику для замены или разрешения символов
    // На данный момент просто возвращаем исходный код
    return code;
}

void Linker::link(const std::vector<std::string>& objectFiles, const std::string& outputFile) {
    try {
        // Объединение объектных файлов
        std::string mergedCode = mergeObjectCodes(objectFiles);
        
        // Разрешение символов (пустая реализация для примера)
        std::string resolvedCode = resolveSymbols(mergedCode);
        
        // Запись окончательного объектного кода в файл
        std::ofstream outFile(outputFile);
        if (!outFile) {
            throw std::runtime_error("Error: Could not open output file " + outputFile);
        }
        outFile << resolvedCode;
        std::cout << "Linking completed successfully. Output file: " << outputFile << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
