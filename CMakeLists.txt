cmake_minimum_required(VERSION 3.10)
project(AppleScript LANGUAGES CXX)

# Указываем стандарт C++ и версию
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Включаем папку src для поиска исходных файлов
add_subdirectory(src)

# Включаем папку tests для сборки тестов
add_subdirectory(tests)

# Указываем папку для документации (необходима, если документация требует специального построения)
add_subdirectory(docs)
