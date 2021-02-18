
CC = gcc
CFLAGS = -Wall

hello: hello.o greeting.o factorial.o
	$(CC) hello.o greeting.o factorial.o -o hello

hello.o: hello.c
	$(CC) $(CFLAGS) -c hello.c

greeting.o: greeting.c
	$(CC) $(CFLAGS) -c greeting.c

factorial.o: factorial.c
	$(CC) $(CFLAGS) -c factorial.c
