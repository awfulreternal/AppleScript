#include <iostream>
#include <string>

namespace as {

/**
 * @brief Выводит сообщение в стандартный вывод.
 * 
 * Использует std::cout для вывода строки с последующим переходом на новую строку.
 * 
 * @param message Строка, которая будет выведена на экран.
 */
void print(const std::string& message) {
    std::cout << message << std::endl;
}

} // namespace as
