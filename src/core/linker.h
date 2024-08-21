#ifndef LINKER_H
#define LINKER_H

#include <string>
#include <vector>

class Linker {
public:
    // Основной метод линковки, поддерживающий несколько объектных файлов
    void link(const std::vector<std::string>& objectFiles, const std::string& outputFile);

private:
    // Функция для объединения объектных файлов в один
    std::string mergeObjectCodes(const std::vector<std::string>& objectFiles);

    // Функция для разрешения символов в коде
    std::string resolveSymbols(const std::string& code);
};

#endif // LINKER_H
