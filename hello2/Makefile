
CC = gcc
CFLAGS = -Wall

hello: hello.o greeting.o factorial.o
	$(CC) $^ -o $@

hello.o: hello.c
	$(CC) $(CFLAGS) -c $<

greeting.o: greeting.c
	$(CC) $(CFLAGS) -c $<

factorial.o: factorial.c
	$(CC) $(CFLAGS) -c $<
