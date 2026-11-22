# Chapter 8 - Multi-Player Tic-Tac-Toe Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = tictactoe.c
EXEC    = tictactoe

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC) scoreboard.txt temp.txt
