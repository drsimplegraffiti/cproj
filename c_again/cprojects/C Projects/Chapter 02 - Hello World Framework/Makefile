# Chapter 2 - Hello World Framework Makefile
CC      = gcc
CFLAGS  = -Iinclude -Wall -Wextra -g   /* -Iinclude lets #include "greetings.h" resolve */
SRC     = src/main.c src/greetings.c
OBJ     = $(SRC:.c=.o)
EXEC    = hello

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
