#ifndef LINKER_H
#define LINKER_H

#include <string>
#include <vector>

// Класс для линковки объектных файлов
class Linker {
public:
    // Основной метод линковки, поддерживающий несколько объектных файлов
    void link(const std::vector<std::string>& objectFiles, const std::string& outputFile);

private:
    // Функция для объединения объектных файлов в один код
    std::string mergeObjectCodes(const std::vector<std::string>& objectFiles) const;

    // Функция для разрешения символов и ссылок в объединенном коде
    std::string resolveSymbols(const std::string& code) const;
};

#endif // LINKER_H
