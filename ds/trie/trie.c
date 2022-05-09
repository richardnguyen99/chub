#include "trie.h"

int __validate(const char *key)
{
    unsigned char c;

    while ((c = *key) && (isalpha(c)))
        ++key;
    return c == '\0';
}

trie *allocate()
{
    trie *new = (trie *)malloc(sizeof(trie));

    if (new == NULL)
        return TRIE_FAIL;

    for (unsigned i = 0; i < ALPHABUFFER; i++)
    {
        new->_children[i] = (void *)NULL;
    }

    new->_end = 0;

    return new;
}

int insert(trie *node, const char *key)
{
    if (node == NULL)
        return TRIE_NULT;

    if (!__validate(key))
        return TRIE_INVL;

    trie *curr = node;
    unsigned char c;

    while ((c = *key))
    {
        int index = c - (int)'a';

        if (index < 0)
            index = c - (int)'A';

        if (!curr->_children[index])
        {
            curr->_children[index] = allocate();
        }

        if (curr->_children[index] == TRIE_FAIL)
            return TRIE_INTC;

        if (curr->_end == 1)
            return 0;

        curr = curr->_children[index];
        ++key;
    }

    curr->_end = 1;

    return 1;
}

int search(trie *node, const char *key)
{
    if (node == NULL)
        return TRIE_NULT;

    if (!__validate(key))
        return TRIE_INVL;

    trie *curr = node;
    unsigned char c;

    while ((c = *key))
    {
        int index = c - (int)'a';

        if (index < 0)
            index = c - (int)'A';

        ++key;
        curr = curr->_children[index];

        if (!curr)
            return 0;
    }

    return (curr->_end);
}

int __haschildren(trie *node)
{
    for (int i = 0; i < ALPHABUFFER; i++)
    {
        if (node->_children[ALPHABUFFER])
            return 1;
    }

    return 0;
}

int delete (trie **node, const char *key)
{
    if (node == NULL)
        return TRIE_NULT;

    if (!__validate(key))
        return TRIE_INVL;

    int status = 0;

    if (*key)
    {
        int index = *key - (int)'a';

        if (index < 0)
            index = *key - (int)'A';

        if ((*node)->_children[index])
            status = delete (&(*node)->_children[index], key + 1);

        if (status == 1 && !(*node)->_end)
        {
            if (!__haschildren(*node))
            {
                free(*node);
                (*node) = NULL;
                return 1;
            }

            return 0;
        }
    }

    if (*key == '\0' && (*node)->_end)
    {
        if (!__haschildren(*node))
        {
            free(*node);
            *node = NULL;

            return 1;
        }

        (*node)->_end = 0;
    }

    return 0;
}

int dealloctrie(trie **node)
{
    if (*node == NULL)
        return TRIE_NULT;

    for (int i = 0; i < ALPHABUFFER; i++)
    {
        if ((*node)->_children[i])
            dealloctrie(&(*node)->_children[i]);
    }

    free(*node);
    *node = NULL;

    return 0;
}
