#ifndef LINKER_H
#define LINKER_H

#include <string>
#include <vector>

/**
 * @class Linker
 * @brief Класс для линковки объектных файлов.
 */
class Linker {
public:
    /**
     * @brief Основной метод линковки, поддерживающий несколько объектных файлов.
     * @param objectFiles Список имен объектных файлов для линковки.
     * @param outputFile Имя выходного файла, в который будет записан результат.
     */
    void link(const std::vector<std::string>& objectFiles, const std::string& outputFile);

private:
    /**
     * @brief Функция для объединения объектных файлов в один код.
     * @param objectFiles Список имен объектных файлов.
     * @return Объединенный объектный код в виде строки.
     */
    std::string mergeObjectCodes(const std::vector<std::string>& objectFiles) const;

    /**
     * @brief Функция для разрешения символов и ссылок в объединенном коде.
     * @param code Исходный объединенный объектный код.
     * @return Объединенный объектный код с разрешенными символами.
     */
    std::string resolveSymbols(const std::string& code) const;
};

#endif // LINKER_H
