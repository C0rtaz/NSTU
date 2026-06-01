CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: build run clean

build: main.c
	$(CC) $(CFLAGS) main.c -o main

run:
	./main

clean:
	rm -rf main

.PHONY: all build clean