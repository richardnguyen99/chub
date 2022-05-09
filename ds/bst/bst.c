#include "bst.h"

int __deleteleaffrom(struct __tree **_node, int _x)
{
    if ((*_node) == NULL)
        return 0;

    return delete (_node, _x);
}

void __replacetree(struct __tree **_src, struct __tree *_dest)
{
    struct __tree *tmp = *_src;
    *_src = _dest;
    free(tmp);
}

int insert(struct __tree **_node, int _x)
{
    if (*_node == NULL)
    {
        (*_node) = (struct __tree *)malloc(sizeof(struct __tree));

        if (*_node == NULL)
            return EERRC;

        (*_node)->_val = _x;
        (*_node)->_left = NULL;
        (*_node)->_right = NULL;

        return 0;
    }

    if (_x < (*_node)->_val)
        return insert(&((*_node)->_left), _x);

    if (_x > (*_node)->_val)
        return insert(&((*_node)->_right), _x);

    return EDUPS;
}

int deallocate(struct __tree **_node)
{
    if (*_node == NULL)
        return ENULT;

    if ((*_node)->_left)
        deallocate(&(*_node)->_left);

    if ((*_node)->_right)
        deallocate(&(*_node)->_right);

    free(*_node);
    *_node = NULL;

    return 0;
}

int contain(struct __tree **_node, int _x)
{
    if (*_node == NULL)
        return ENULT;

    if ((*_node)->_val == _x)
        return 1;

    return (contain(&(*_node)->_left, _x) == 1 || contain(&(*_node)->_right, _x) == 1) ? 1 : 0;
}

int count(struct __tree **_node)
{
    if (*_node == NULL)
        return ENULT;

    int c = 1;

    if ((*_node)->_left)
        c += count(&(*_node)->_left);
    if ((*_node)->_right)
        c += count(&(*_node)->_right);

    return c;
}

int height(struct __tree **_node)
{
    if (*_node == NULL)
        return ENULT;

    int left_height = 0;
    int right_height = 0;

    if ((*_node)->_left)
        left_height = height(&(*_node)->_left) + 1;
    if ((*_node)->_right)
        right_height = height(&(*_node)->_right) + 1;

    return left_height > right_height ? left_height : right_height;
}

int balanced(struct __tree **_node)
{
    if (*_node == NULL)
        return ENULT;

    int leftheight = height(&(*_node)->_left);
    int rightheight = height(&(*_node)->_right);

    int heightdiff = leftheight < rightheight ? (rightheight - leftheight) : (leftheight - rightheight);

    return (heightdiff < 2) ? 1 : 0;
}

void inorderprint(const struct __tree *_node)
{
    if (_node == NULL)
        fprintf(stderr, "Empty");

    if (_node->_left)
        inorderprint(_node->_left);

    fprintf(stdout, "%d ", _node->_val);

    if (_node->_right)
        inorderprint(_node->_right);
}

void preorderprint(const struct __tree *_node)
{
    if (_node == NULL)
        fprintf(stderr, "Empty");

    fprintf(stdout, "%d ", _node->_val);

    if (_node->_left)
        inorderprint(_node->_left);

    if (_node->_right)
        inorderprint(_node->_right);
}

void postorderprint(const struct __tree *_node)
{
    if (_node == NULL)
        fprintf(stderr, "Empty");

    if (_node->_left)
        inorderprint(_node->_left);

    if (_node->_right)
        inorderprint(_node->_right);

    fprintf(stdout, "%d ", _node->_val);
}

struct __tree *successor(struct __tree *_node)
{
    struct __tree *node = _node;

    while (node && node->_left != NULL)
        node = node->_left;

    return node;
}

int delete (struct __tree **_node, int _x)
{
    if (*_node == NULL)
        return ENULT;

    if (_x < (*_node)->_val)
        return __deleteleaffrom(&(*_node)->_left, _x);
    else if (_x > (*_node)->_val)
        return __deleteleaffrom(&(*_node)->_right, _x);

    if ((*_node)->_left && (*_node)->_right)
    {
        struct __tree *next = successor((*_node)->_right);

        (*_node)->_val = next->_val;
        return delete (&next, next->_val);
    }

    if ((*_node)->_left == NULL && (*_node)->_right == NULL)
    {
        deallocate(_node);
        return 1;
    }

    if ((*_node)->_left == NULL)
        __replacetree(_node, (*_node)->_right);
    if ((*_node)->_right == NULL)
        __replacetree(_node, (*_node)->_left);

    return 1;
}
