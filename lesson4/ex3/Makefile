CC=gcc
CFLAGS=-pthread -Wall

all: pc
pc: producer_consumer.c
	$(CC) $(CFLAGS) -o $@ $<
run: pc
	./pc
clean:
	rm -f pc
