.PHONY: clean
CC=gcc
CFLAGS=-Wall -c
all: main

main: main.o add_int.o multi_int.o
	$(CC) main.o add_int.o multi_int.o

main.o:
	$(CC) $(CFLAGS) main.c

add_int.o:
	$(CC) $(CFLAGS) add_int.c

multi_int.o:
	$(CC) $(CFLAGS) multi_int.c

clean:
	rm *.o