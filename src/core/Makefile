# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -MMD -MP
LDFLAGS =

# Исходные файлы
SRC = main.cpp parser.cpp ast.cpp semantic_analysis.cpp codegen.cpp optimizer.cpp linker.cpp error_handler.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)
EXEC = my_compiler

# Правила сборки
all: $(EXEC)

# Сборка исполняемого файла
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Компиляция исходных файлов в объектные файлы
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

# Генерация зависимостей
-include $(DEP)

# Очистка сгенерированных файлов
clean:
	rm -f $(OBJ) $(DEP) $(EXEC)

# Очистка всех файлов, включая временные
distclean: clean
	rm -f *~ *.swp

# Правило по умолчанию для параллельной сборки
.PHONY: all clean distclean
