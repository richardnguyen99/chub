#include <stdio.h>

#include "bst.h"

int main(int argc, char **argv)
{
    bstree *tree = NULL;

    insert(&tree, 5);
    insert(&tree, 3);
    insert(&tree, 8);
    insert(&tree, 1);
    insert(&tree, 2);
    insert(&tree, 7);
    insert(&tree, 6);
    insert(&tree, 3);

    fprintf(stdout, "tree contains 5?: %d\n", contain(&tree, 5));
    fprintf(stdout, "tree contains 1?: %d\n", contain(&tree, 1));

    fprintf(stdout, "total nodes in tree: %d\n", count(&tree));
    fprintf(stdout, "tree height: %d\n", height(&tree));
    fprintf(stdout, "tree is balanced?: %d\n", balanced(&tree));

    fprintf(stdout, "in-order print tree: ");
    inorderprint(tree);
    fprintf(stdout, "\n");

    fprintf(stdout, "pre-order print tree: ");
    preorderprint(tree);
    fprintf(stdout, "\n");

    fprintf(stdout, "post-order print tree: ");
    postorderprint(tree);
    fprintf(stdout, "\n");

    fprintf(stdout, "delete 8 from tree: %d\n", delete (&tree, 8));

    fprintf(stdout, "in-order print tree: ");
    inorderprint(tree);
    fprintf(stdout, "\n");

    fprintf(stdout, "delete 2 from tree: %d\n", delete (&tree, 2));

    fprintf(stdout, "in-order print tree: ");
    inorderprint(tree);
    fprintf(stdout, "\n");

    fprintf(stdout, "delete 7 from tree: %d\n", delete (&tree, 7));

    fprintf(stdout, "in-order print tree: ");
    inorderprint(tree);
    fprintf(stdout, "\n");

    fprintf(stdout, "total nodes in tree: %d\n", count(&tree));
    fprintf(stdout, "tree height: %d\n", height(&tree));

    insert(&tree, 7);
    insert(&tree, 8);
    insert(&tree, 9);
    insert(&tree, 10);
    insert(&tree, 11);
    insert(&tree, 12);

    fprintf(stdout, "in-order print tree: ");
    inorderprint(tree);
    fprintf(stdout, "\n");

    fprintf(stdout, "total nodes in tree: %d\n", count(&tree));
    fprintf(stdout, "tree height: %d\n", height(&tree));
    fprintf(stdout, "tree is balanced?: %d\n", balanced(&tree));

    if (deallocate(&tree) == 0)
        fprintf(stdout, "tree is deallocated successfully\n");
    else
        fprintf(stderr, "tree dellocation fails\n");

    return 0;
}
