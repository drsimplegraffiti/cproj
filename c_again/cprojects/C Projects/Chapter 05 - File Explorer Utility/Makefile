# Chapter 5 - File Explorer Utility Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = file_explorer.c
EXEC    = file_explorer

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
