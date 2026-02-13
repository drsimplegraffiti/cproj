CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = inmemdb
SRC = main.c db.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

