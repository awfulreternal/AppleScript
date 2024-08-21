# Добавляем исходные файлы для тестов
set(TEST_SOURCES
    test_lexer.apple
)

# Создаем исполняемый файл для тестов
add_executable(run_tests ${TEST_SOURCES})

# Указываем зависимости и библиотеки
target_link_libraries(run_tests applescript)
