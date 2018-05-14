CXX=g++
CXXFLAGS=-Wall
CXXFLAGS+=-std=c++11
CXXFLAGS+=-g
NAME=atest

DEP_FLAGS=-MMD
DEP_FLAGS+=-MP
CXXFLAGS+=$(DEP_FLAGS)

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXX_FLAGS) $(OBJ) -o $@

.PHONY: clean run valgrind class fullvalgrind

clean: 
	rm -rf $(NAME) $(DEP) $(OBJ)

run: 
	./$(NAME)

valgrind:
	valgrind --leak-check=yes ./$(NAME)

fullvalgrind:
	valgrind --leak-check=yes --show-leak-kinds=all ./$(NAME)


class: 
	read -p "Enter Class Name:" name; \
	touch $$name.cpp; \
	printf "#include \""$$name.h"\"\n\n#include <iostream>\n\nusing namespace std;\n" > $$name.cpp; \
	touch $$name.h; \
	printf "#pragma once\n\nclass "$$name"{\npublic:\n\nprivate:\n\n};\n" > $$name.h


-include $(DEP)
