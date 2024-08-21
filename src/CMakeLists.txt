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
