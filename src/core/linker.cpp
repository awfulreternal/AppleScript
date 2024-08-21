#include "linker.h"
#include <fstream>

void Linker::link(const std::string& objectCode, const std::string& outputFile) {
    // Пример записи объектного кода в файл
    std::ofstream outFile(outputFile);
    outFile << objectCode;
    outFile.close();
}
