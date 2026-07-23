# CC=gcc
# CCFLAGS= -ggdb3
#
# default: prog
#
# main.o : main.c
# 	$(CC) $(CCFLAGS) -c main.c
#
# prog: main.o
# 	$(CC) $(CCFLAGS) main.o -o prog
#
# run:
# 	gdb ./prog
#
# clean:
# 	rm main.o
# 	rm prog
CC      = gcc
CFLAGS  = -g -Wall -std=c99
LIBS    = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

default: prog

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

prog: main.o
	$(CC) $(CFLAGS) main.o -o prog $(LIBS)

run:
	./prog

clean:
	rm -f main.o prog
#
# make && make run
