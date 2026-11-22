# Chapter 19 - Virtual Machine Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = vm.c
EXEC    = vm

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
