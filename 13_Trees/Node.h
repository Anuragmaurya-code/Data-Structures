#ifndef NODE_H
#define NODE_H

typedef struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

extern Node *root;

#endif