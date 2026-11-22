# Chapter 11 - Chat App Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g

.PHONY: all clean run-server run-client

all: server client

server: server.c
	$(CC) $(CFLAGS) -o server server.c

client: client.c
	$(CC) $(CFLAGS) -o client client.c

run-server:
	./server

run-client:
	./client

clean:
	rm -f server client
