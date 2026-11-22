# Chapter 14 - Custom Memory Allocator Makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g

.PHONY: all clean run

all: allocator_test

allocator_test: allocator_test.c allocator.c
	$(CC) $(CFLAGS) -o allocator_test allocator_test.c allocator.c

run: allocator_test
	./allocator_test

clean:
	rm -f allocator_test
