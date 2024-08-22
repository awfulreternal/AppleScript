# Добавляем исходные файлы
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

# Указываем зависимости
find_package(CURL REQUIRED)
target_link_libraries(applescript PRIVATE CURL::libcurl)

# Указываем директории с заголовочными файлами
target_include_directories(applescript PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/stdlib
)

# Указание флагов компиляции
target_compile_options(applescript PRIVATE
    -Wall
    -Wextra
    -Werror
)

# Установка флагов для отладки
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Настройки платформ
if(WIN32)
    target_compile_definitions(applescript PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(applescript PRIVATE PLATFORM_MACOS)
endif()

# Оптимизация и сборка
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
