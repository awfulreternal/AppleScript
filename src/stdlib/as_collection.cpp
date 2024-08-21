#include "as_collections.h"
#include <algorithm>

/**
 * @brief Сортирует массив целых чисел по возрастанию.
 * 
 * @param arr Вектор целых чисел, который нужно отсортировать.
 */
void sortArray(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

/**
 * @brief Обратная сортировка массива целых чисел.
 * 
 * @param arr Вектор целых чисел, который нужно отсортировать в обратном порядке.
 */
void reverseSortArray(std::vector<int>& arr) {
    std::sort(arr.rbegin(), arr.rend());
}

/**
 * @brief Поиск минимального элемента в массиве целых чисел.
 * 
 * @param arr Вектор целых чисел, среди которых нужно найти минимум.
 * @return Минимальное значение в массиве.
 */
int findMin(const std::vector<int>& arr) {
    return *std::min_element(arr.begin(), arr.end());
}

/**
 * @brief Поиск максимального элемента в массиве целых чисел.
 * 
 * @param arr Вектор целых чисел, среди которых нужно найти максимум.
 * @return Максимальное значение в массиве.
 */
int findMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}
