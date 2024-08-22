# Указываем исходные файлы для тестов
set(TEST_SOURCES
    test_lexer.apple
    # Здесь можно добавить другие тестовые файлы
)

# Создаем исполняемый файл для тестов
add_executable(run_tests ${TEST_SOURCES})

# Указываем зависимости и библиотеки
target_link_libraries(run_tests applescript)

# Указываем, что run_tests зависит от основного исполняемого файла
add_dependencies(run_tests applescript)

# Указываем путь к директории с тестами (для более организованной структуры проекта)
set_target_properties(run_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests")
