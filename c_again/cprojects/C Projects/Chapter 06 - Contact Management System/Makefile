# Chapter 6 - Contact Management System Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = main.c contact.c
OBJ     = $(SRC:.c=.o)
EXEC    = contact_manager

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC) contacts.bin
