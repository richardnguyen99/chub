#ifndef __BST_H
#define __BST_H

#include <stdio.h>  // fprintf, stdout, stderr
#include <stddef.h> // NULL
#include <stdlib.h> // malloc, free

#define EERRC -1 /* Internal C error */
#define EDUPS -2 /* Duplicate in tree */
#define ENULT -3 /* Null tree */

struct __tree
{
    int _val;
    struct __tree *_left;
    struct __tree *_right;
};

typedef struct __tree bstree;

int insert(struct __tree **_node, int _x);
int contain(struct __tree **_node, int _x);
int count(struct __tree **_node);
int delete (struct __tree **node, int _x);
int deallocate(struct __tree **_node);
int height(struct __tree **_node);
int balanced(struct __tree **_node);

void inorderprint(const struct __tree *_node);
void preorderprint(const struct __tree *_node);
void postorderprint(const struct __tree *_node);

struct __tree *successor(struct __tree *_node);
struct __tree *predecessor(struct __tree *_node);

int __deleteleaffrom(struct __tree **_node, int _x);
void __replacetree(struct __tree **_src, struct __tree *_dest);

#endif // __BST_H
