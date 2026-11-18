
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra

SRC = src/operations.c ./calculator.c
OBJ = $(SRC:.c=.o)
EXEC = app

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
