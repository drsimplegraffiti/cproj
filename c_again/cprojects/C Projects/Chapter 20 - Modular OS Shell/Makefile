# Chapter 20 - Modular OS Shell Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = main.c commands.c memory.c
OBJ     = $(SRC:.c=.o)
EXEC    = shell

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)
