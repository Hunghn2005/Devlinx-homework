CC = gcc
CFLAGS = -Wall -Wextra -O2 -pthread

.PHONY: all run clean

all: thread_basic

thread_basic: thread_basic.c
	$(CC) $(CFLAGS) -o $@ $<

run: thread_basic
	./thread_basic

clean:
	rm -f thread_basic
