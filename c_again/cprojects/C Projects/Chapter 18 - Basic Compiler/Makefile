# Chapter 18 - Basic Compiler Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = compiler.c
EXEC    = compiler

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
