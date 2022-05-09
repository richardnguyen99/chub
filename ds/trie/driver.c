#include <stdio.h>
#include <string.h>

#include "trie.h"

int main(int argc, char **argv)
{
    trie *t = allocate();

    insert(t, "strings");
    insert(t, "string");

    fprintf(stdout, "Trie contains \"string\"?: %d\n", search(t, "string"));

    fprintf(stdout, "Delete \"string\" from trie: %d\n", delete (&t, "string"));
    fprintf(stdout, "Trie contains \"string\"?: %d\n", search(t, "string"));
    fprintf(stdout, "Trie contains \"strings\"?: %d\n", search(t, "strings"));

    printf("\n");
    if (dealloctrie(&t) == 0)
        fprintf(stdout, "Trie has been deallocated\n");
    else
        fprintf(stderr, "Trie cannot be deallocated completely\n");

    return 0;
}
