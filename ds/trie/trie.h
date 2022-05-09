#ifndef __TRIE_H
#define __TRIE_H

#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

#define ALPHABUFFER 52
#define LOWERCASE 26
#define MSGBUFFER 128

#define TRIE_FAIL ((void *)-1) /* Cannot create trie */
#define TRIE_INTC -1           /* Internal C error */
#define TRIE_DUPS -2           /* Duplicate in tree */
#define TRIE_NULT -3           /* Null tree */
#define TRIE_INVL -4           /* Invalid input*/

struct __trie
{
    struct __trie *_children[ALPHABUFFER];
    int _end;
};

typedef struct __trie trie;

trie *allocate(void);
int insert(trie *node, const char *key);
int search(trie *node, const char *key);
int delete (trie **node, const char *key);
int dealloctrie(trie **node);

int __validate(const char *key);
int __haschildren(trie *node);

#endif // __TRIE_H
