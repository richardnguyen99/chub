CC=gcc
CFLAGS=-g -Wall -Werror

all: bst.o bstdriver.o
	$(CC) bst.o bstdriver.o -o bst

bst.o: bst.c
	$(CC) $(CFLAGS) -o bst.o -c bst.c

bstdriver.o: bstdriver.c
	$(CC) $(CFLAGS) -o bstdriver.o -c bstdriver.c

clean:
	rm -rf bst *.o
