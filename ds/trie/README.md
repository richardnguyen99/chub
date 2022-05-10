## Trie - Re-TRIE-val tree

Trie is an tree-liked data structure that stores, insert, retrieves and deletes strings efficiently. Trie guarantees that a string retrievial operation only takes $O(n)$ in runtime, where $m$ is the length of the string.

For more details on implementation, please check the source codes:

- `trie.h` <span>&mdash;</span> Header file for trie
- `trie.c` <span>&mdash;</span> Implementation file for trie
- `driver.c` <span>&mdash;</span> Simple demonstration how to use trie

## Summary

Unlike binary search tree, nodes in a trie do not store associated key. Instead, a node's position in the trie defines they with which it is located.

The implementation of trie represented here only deals with Latin alphabet, including uppercase and lowercase.

A root of a trie responds to the empty string.

## Run

```sh
make        # Build the program
./trie      # Run the driver

make clean  # Clean up (optional)
```

## Usage

### Type definition

```c
struct __trie
{
    struct __trie *_children[ALPHABUFFER];
    int _end;
};

typedef struct __trie trie;
```

### `trie* allocate()`

The `allocate()` function allocates a new trie. On success, it returns a pointer pointing to the newly allocated space. On error, no memory is allocated and it returns an associated error code to indicate what causes the error.

    TRIE_FAIL ((void *) -1): Unable to allocate a new trie

### `int insert(trie* node, const char* key)`:

The `insert()` function inserts a new KEY into a given trie. On success, it returns 0 to indicate a new key has been inserted. On error, the function returns an associated error code to indicate what causes the error.

    TRIE_INTC (-1): There is an internal error coming from the C compiler. In this case, tree cannot be allocated.

    TRIE_NULT (-3): A trie is null.

    TRIE_INVL (-4): An invalid key is being attempted to use, which contains characters that are not alphabetical.


### `int search(trie *node, const char* key)`:

The `search()` function searches a KEY in a given trie. On success, it returns 1 when the given key is existing, or 0 otherwise. On error, the function returns an associated error code to indicate what causes the error.

    TRIE_NULT (-3): A trie is null.

    TRIE_INVL (-4): An invalid key is being attempted to use, which contains characters that are not alphabetical.

### `int delete(trie **node, const char* key)`:

The `delete()` function attempts to remove a KEY from a given trie. On success, it returns 1 when the given key was there and was removed, or 0 to indicate there was no such key. On error, the function returns an associated error code to indicate what causes the error.

    TRIE_NULT (-3): A trie is null.

    TRIE_INVL (-4): An invalid key is being attempted to use, which contains characters that are not alphabetical.

### `int dealloctrie(trie **node)`

The `dealloctrie()` function frees memory addresses associated with a given tree. On success, it returns 0. On error, the function returns an associated error code to indicate what causes the error.

    TRIE_NULT (-3): A trie is null.
