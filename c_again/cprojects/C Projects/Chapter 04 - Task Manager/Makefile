# Chapter 4 - Task Manager Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = main.c task.c
OBJ     = $(SRC:.c=.o)
EXEC    = task_manager

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC) tasks.txt
