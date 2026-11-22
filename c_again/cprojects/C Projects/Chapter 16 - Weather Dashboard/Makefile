# Chapter 16 - Weather Dashboard Makefile
# Requires libcurl and cJSON development packages.
CC      = gcc
CFLAGS  = -Wall -Wextra -g
LDFLAGS = -lcurl -lcjson
SRC     = weather_dashboard.c
EXEC    = weather_dashboard

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
