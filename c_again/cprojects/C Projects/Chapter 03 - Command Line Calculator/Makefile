# Chapter 3 - Command-Line Calculator Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = calculator.c operations.c
OBJ     = $(SRC:.c=.o)
EXEC    = calculator

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
