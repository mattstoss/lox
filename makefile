CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror -Wconversion -Wsign-conversion

TARGET = lox

SOURCES = src/ast.c src/main.c src/scanner.c src/token.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean