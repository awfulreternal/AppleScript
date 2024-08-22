# Указываем исходные файлы для тестов
set(TEST_SOURCES
    test_lexer.apple
    # Здесь можно добавить другие тестовые файлы
)

# Создаем исполняемый файл для тестов
add_executable(run_tests ${TEST_SOURCES})

# Указываем, что run_tests зависит от основного исполняемого файла
# Обычно это делается для обеспечения правильного порядка сборки, но в данном случае
# если run_tests не зависит от других целей, можно опустить эту часть

# Указываем путь к директории с тестами (для более организованной структуры проекта)
set_target_properties(run_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
)

# Если есть библиотеки или зависимости для тестов, указываем их
# Например, если используются библиотеки для работы с AppleScript или другие зависимости
# target_link_libraries(run_tests applescript)

# Добавляем тесты в проект, если используетсяCTest
enable_testing()
add_test(NAME run_tests COMMAND run_tests)
