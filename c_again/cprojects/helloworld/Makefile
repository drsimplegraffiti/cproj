CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c99 -Iinclude

TARGET = main
SRC = src/main.c src/greetings.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
