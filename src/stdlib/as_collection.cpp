#include "as_collections.h"
#include <algorithm>
#include <vector>

/**
 * @brief Сортирует вектор целых чисел по возрастанию.
 * 
 * Эта функция использует стандартный алгоритм `std::sort` для упорядочивания элементов 
 * вектора в порядке возрастания. Она изменяет порядок элементов в исходном векторе.
 * 
 * @param arr Вектор целых чисел, который нужно отсортировать.
 */
void sortArray(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

/**
 * @brief Сортирует вектор целых чисел в обратном порядке (по убыванию).
 * 
 * Эта функция использует стандартный алгоритм `std::sort` с реверсивным итератором для 
 * упорядочивания элементов вектора в порядке убывания. Она изменяет порядок элементов 
 * в исходном векторе.
 * 
 * @param arr Вектор целых чисел, который нужно отсортировать в обратном порядке.
 */
void reverseSortArray(std::vector<int>& arr) {
    std::sort(arr.rbegin(), arr.rend());
}

/**
 * @brief Находит минимальный элемент в векторе целых чисел.
 * 
 * Эта функция использует стандартный алгоритм `std::min_element` для поиска минимального 
 * значения в векторе. Если вектор пуст, функция поведет себя неопределенно.
 * 
 * @param arr Вектор целых чисел, среди которых нужно найти минимальное значение.
 * @return Минимальное значение в векторе.
 */
int findMin(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw std::runtime_error("Cannot find minimum in an empty vector.");
    }
    return *std::min_element(arr.begin(), arr.end());
}

/**
 * @brief Находит максимальный элемент в векторе целых чисел.
 * 
 * Эта функция использует стандартный алгоритм `std::max_element` для поиска максимального 
 * значения в векторе. Если вектор пуст, функция поведет себя неопределенно.
 * 
 * @param arr Вектор целых чисел, среди которых нужно найти максимальное значение.
 * @return Максимальное значение в векторе.
 */
int findMax(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw std::runtime_error("Cannot find maximum in an empty vector.");
    }
    return *std::max_element(arr.begin(), arr.end());
}
