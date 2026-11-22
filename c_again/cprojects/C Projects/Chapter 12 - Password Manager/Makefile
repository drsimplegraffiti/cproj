# Chapter 12 - Password Manager Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = password_manager.c
EXEC    = password_manager

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC) passwords.dat
