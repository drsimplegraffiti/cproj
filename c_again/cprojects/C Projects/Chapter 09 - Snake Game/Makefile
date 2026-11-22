# Chapter 9 - Snake Game Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = snake.c
EXEC    = snake

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
