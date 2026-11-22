CC      ?= cc
CFLAGS  ?= -std=c99 -Wall -Wextra -I.
LDLIBS  := -lsqlite3

SRCS := main.c task.c
OBJS := $(SRCS:.c=.o)
TARGET := todo

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)

%.o: %.c task.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) tasks.db
