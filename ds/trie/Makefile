CC=gcc
CFLAGS=-g -Wall -Werror

all: trie.o driver.o
	$(CC) trie.o driver.o -o main

trie.o: trie.c
	$(CC) $(CFLAGS) -o trie.o -c trie.c

driver.o: driver.c
	$(CC) $(CFLAGS) -o driver.o -c driver.c

clean:
	rm -rf trie driver *.o
