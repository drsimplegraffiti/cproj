CC=gcc
CCFLAGS= -ggdb3

default: prog

main.o : main.c
	$(CC) $(CCFLAGS) -c main.c

prog: main.o
	$(CC) $(CCFLAGS) main.o -o prog

run:
	gdb ./prog

clean:
	rm main.o
	rm prog
