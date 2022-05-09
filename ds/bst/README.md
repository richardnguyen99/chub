# Binary search tree

Binary search tree is a binary tree data structure with a constraint in which the left child has a value that is smaller the one in its parent node, while the right child has a bigger value.

For more implementation detail, please check the source codes:

- `bst.h` <span>&mdash;</span> Header file for binary search tree
- `bst.c` <span>&mdash;</span> Implementation file for binary search tree
- `driver.c` <span>&mdash;</span> Simple demonstration how to use binary search tree

## Run

```sh
make    # Build the program
./bst   # Run the driver

# Optional
make clean  # Clean all the binary and object files
```

## Usage

Binary search tree must maintain the constraint spoken above. Therefore, every modification function upons an existing tree must follow it.

### Type definition

```c
struct __tree
{
    int _val;
    struct __tree *_left;
    struct __tree *_right;
};

typedef struct __tree bstree;
```

### `insert(tree **node, int x)`

The `insert()` function inserts a new value into a tree. If the tree is null, it will be allocated then inserted the new value. On success, the function returns 0. On fail, the function returns an associated error code to indicate what causes the error.

    EERRC (-1): There is an internal error coming from the C compiler. In this case, tree cannot be allocated.

    EDUPS (-2): There is an exact value existing in the tree already.

### `contain(tree **node, int x)`

The `contain()` function checks if a value exists in a given tree. On success, the function returns 0 if it does exist and 1 otherwise. On error, the function returns an associated error code to indicate what causes the error.

    ENULT (-3): The given tree is currently null.

### `count(tree **node)`

The `count()` function counts how many node there are in a given tree. On success, the function returns the total number of nodes in the tree. On error, the function returns an associated error code to indicate what causes the error.

    ENULT (-3): The given tree is currently null.

### `height(tree **node)`

The `height()` function counts the height of a given tree. On success, the function returns the largest path from the node passed in the function to its leaf. On error, the function returns an associated error code to indicate what causes the error.

    ENULT (-3): The given tree is currently null.

### `deallocate(tree **node)`

The `deallocate()` function frees the memory space used by node and its sub-trees. On success, the function returns 0. On error, the function returns an associated error code to indicate what causes the error.

    ENULT (-3): The given tree is currently null.

The `deallocate()` function only responds the given tree and has no impact on the parent. It's client's responsibility to keep track and use this function correctly. To remove a particular value, see `delete()`.

### `delete(tree **node, int x)`

The `delete()` function removes a value from tree. On success, the function returns 1 if there was an existing value to remove, or 0 if there was none. On error, the function returns an associated error code to indicate what causes the error.

    ENULT (-3): The given tree is currently null.

### `balanced(tree **node)`

The `balanced()` function checks if a given tree is balanced or not. On success, the function returns 1 if it's balanced, or 0 otherwise. On error, the function returns an associated error code to indicate what causes the error.

    ENULT (-3): The given tree is currently null.

A tree is considered balanced when the difference in height of two sub-trees is not greater than 1.

### `inorderprint(const struct tree *node)`

The `inorderprint()` function prints out a given tree in in-order fashion. This function invokes `printf(3)` internally. An empty tree will display "Empty" to the screen.

### `preorderprint(const struct tree *node)`

The `preorderprint()` function prints out a given tree in pre-order fashion. This function invokes `printf(3)` internally. An empty tree will display "Empty" to the screen.

### `postorderprint(const struct tree *node)`

The `postorderprint()` function prints out a given tree in post-order fashion. This function invokes `printf(3)` internally. An empty tree will display "Empty" to the screen.
