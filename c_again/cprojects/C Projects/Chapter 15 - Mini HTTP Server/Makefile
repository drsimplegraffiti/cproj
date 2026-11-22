# Chapter 15 - Mini HTTP Server Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
SRC     = http_server.c
EXEC    = http_server

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
