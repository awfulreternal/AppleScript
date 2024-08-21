# Makefile для сборки компилятора

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS =

# Исходные файлы
SRC = main.cpp parser.cpp ast.cpp semantic_analysis.cpp arm.cpp mips.cpp x86.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = my_compiler

# Правила сборки
all: $(EXEC)

$(EXEC): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ) $(EXEC)

.PHONY: all clean
