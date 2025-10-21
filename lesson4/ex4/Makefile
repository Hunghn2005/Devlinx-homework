CC = gcc
CFLAGS = -pthread -Wall

all: rwlock_demo

rwlock_demo: rwlock_demo.c
	$(CC) $(CFLAGS) -o rwlock_demo rwlock_demo.c

clean:
	rm -f rwlock_demo
