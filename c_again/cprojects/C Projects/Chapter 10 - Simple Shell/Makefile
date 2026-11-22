# Chapter 10 - Simple Shell Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = shell.c
EXEC    = shell

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
