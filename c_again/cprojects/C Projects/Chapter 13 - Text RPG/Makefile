# Chapter 13 - Text RPG Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = rpg.c
EXEC    = rpg

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
