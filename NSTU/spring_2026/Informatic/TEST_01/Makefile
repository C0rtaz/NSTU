CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all: build run clean

build: test1.c test2.c test3.c
	$(CC) $(CFLAGS) test1.c -o test1.out
	$(CC) $(CFLAGS) test2.c -o test2.out
	$(CC) $(CFLAGS) test3.c -o test3.out -lm

run:
	./test1.out
	./test2.out
	./test3.out

clean:
	rm -rf *.out

.PHONY: all build clean run