#include "as_sync.h"
#include <thread>

namespace as {

/**
 * @brief Запускает указанную функцию в отдельном потоке.
 * 
 * Эта функция создает новый поток с использованием `std::thread` и запускает
 * переданную функцию в этом потоке. Поток запускается асинхронно и сразу же
 * отсоединяется от текущего потока, позволяя функции выполняться в фоне.
 * 
 * @param func Указатель на функцию, которая будет выполняться в новом потоке.
 * 
 * @note Функция должна быть свободной функцией (не-членской) и не должна принимать
 *       аргументов. В случае необходимости передачи аргументов, можно использовать
 *       лямбда-выражения или `std::bind`.
 * 
 * @warning Убедитесь, что функция, передаваемая в `startThread`, завершится
 *          корректно, поскольку отсоединенный поток не может быть управляем
 *          после его запуска.
 * 
 * @example
 * // Пример использования
 * void myFunction() {
 *     // Код, выполняемый в фоне
 *     std::cout << "Function running in background" << std::endl;
 * }
 * 
 * int main() {
 *     as::startThread(myFunction);
 *     // Основной поток продолжает выполнение
 *     std::cout << "Main thread continues" << std::endl;
 *     return 0;
 * }
 */
void startThread(void(*func)()) {
    std::thread t(func);
    t.detach(); // Отсоединяем поток для выполнения в фоне
}

} // namespace as
