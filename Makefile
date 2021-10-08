CC=clang++
CFLAGS=-std=c++98 -c #-Wall -Werror -Wextra
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=app

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@echo 'Ready'`$(CC) $(OBJECTS) -o $@`''

.cpp.o:
	@echo 'Compiling...'`$(CC) $(CFLAGS) $< -o $@`''

clean:
	@echo 'Cleaned'`rm -rf $(OBJECTS)`''

fclean: clean
		@echo 'Full cleaned'`rm -rf $(EXECUTABLE)`''

re: fclean all