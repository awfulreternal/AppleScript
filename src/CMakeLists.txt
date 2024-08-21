cmake_minimum_required(VERSION 3.10)

# Название проекта
project(AppleScript)

# Указываем стандарт языка C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исходные файлы для сборки
set(SOURCE_FILES
    core/lexer.cpp
    core/parser.cpp
    core/codegen.cpp
    core/optimizer.cpp
    core/linker.cpp
    core/arch/x86.cpp
    core/arch/arm.cpp
    core/arch/mips.cpp
    core/error_handler.cpp
    core/async.cpp
    stdlib/as_stdio.cpp
    stdlib/as_network.cpp
    stdlib/as_threading.cpp
    stdlib/as_multimedia.cpp
    stdlib/as_cloud.cpp
    main.cpp
)

# Создаем исполняемый файл
add_executable(applescript ${SOURCE_FILES})

# Указываем зависимости, например, cURL для as_network.cpp
find_package(CURL REQUIRED)
target_link_libraries(applescript PRIVATE CURL::libcurl)

# Добавляем папку с заголовочными файлами
include_directories(include)

# Указание флагов компиляции для Windows и macOS
if(WIN32)
    # Настройки для Windows
    target_compile_definitions(applescript PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    # Настройки для macOS
    target_compile_definitions(applescript PRIVATE PLATFORM_MACOS)
endif()

# Включаем предупреждения и ошибки компиляции
target_compile_options(applescript PRIVATE -Wall -Wextra -Werror)

# Включаем отладочную информацию
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
