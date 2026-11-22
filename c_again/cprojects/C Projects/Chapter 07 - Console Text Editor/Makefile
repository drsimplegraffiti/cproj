# Chapter 7 - Console Text Editor Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = editor.c
EXEC    = editor

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC) sample.txt

clean:
	rm -f $(EXEC)
