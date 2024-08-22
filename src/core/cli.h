#ifndef CLI_H
#define CLI_H

#include <string>

/**
 * @class CLI
 * @brief Класс для обработки аргументов командной строки.
 */
class CLI {
public:
    /**
     * @brief Конструктор класса CLI.
     * @param argc Количество аргументов командной строки.
     * @param argv Массив аргументов командной строки.
     */
    CLI(int argc, char* argv[]);

    /**
     * @brief Разбор аргументов командной строки.
     * @return true, если аргументы были разобраны успешно и файл источника указан; иначе false.
     */
    bool parseArguments();

    /**
     * @brief Получение пути к исходному файлу.
     * @return Путь к исходному файлу.
     */
    std::string getSourceFile() const;

    /**
     * @brief Проверка, включен ли verbose режим.
     * @return true, если verbose режим включен; иначе false.
     */
    bool isVerbose() const;

    /**
     * @brief Проверка, требуется ли оптимизация кода.
     * @return true, если требуется оптимизация; иначе false.
     */
    bool shouldOptimize() const;

private:
    int argc;                ///< Количество аргументов командной строки.
    char** argv;             ///< Массив аргументов командной строки.
    std::string sourceFile;  ///< Путь к исходному файлу.
    bool verbose;            ///< Флаг, указывающий, включен ли verbose режим.
    bool optimize;           ///< Флаг, указывающий, требуется ли оптимизация кода.
};

#endif // CLI_H
