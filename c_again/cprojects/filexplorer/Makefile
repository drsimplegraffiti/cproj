CC      ?= cc
CFLAGS  ?= -std=c99 -Wall -Wextra

TARGET := filexplorer
SRCS   := main.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
