# Chapter 17 - Maze Generator & Solver Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = maze.c
EXEC    = maze

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
