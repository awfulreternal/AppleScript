cmake_minimum_required(VERSION 3.10)
project(AppleScript LANGUAGES CXX)

# Указываем стандарт C++ и версию
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Включаем папку src для поиска исходных файлов
add_subdirectory(src)

# Включаем папку tests для сборки тестов (если есть тесты)
add_subdirectory(tests)

# Указываем папку для документации (если есть документация)
add_subdirectory(docs)
