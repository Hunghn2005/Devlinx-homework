CC = gcc
CFLAGS = -pthread -Wall

all: mutex_counter

mutex_counter: mutex_counter.c
	$(CC) $(CFLAGS) -o mutex_counter mutex_counter.c

clean:
	rm -f mutex_counter
