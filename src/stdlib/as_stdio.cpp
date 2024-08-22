#include <iostream>
#include <string>

namespace as {

/**
 * @brief Выводит сообщение в стандартный вывод.
 * 
 * Функция использует `std::cout` для вывода строки, после чего добавляется перевод строки.
 * 
 * @param message Строка, которая будет выведена на экран.
 * 
 * @note Пример использования:
 * @code
 * as::print("Hello, World!");
 * @endcode
 * 
 * В этом примере будет выведено сообщение "Hello, World!" с последующим переходом на новую строку.
 */
void print(const std::string& message) {
    std::cout << message << std::endl;
}

} // namespace as
