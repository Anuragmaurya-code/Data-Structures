#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

struct NodeQueue {
    struct Node** data;
    int front;
    int rear;
    int capacity;
};
void init_NodeQueue(struct NodeQueue* q, int cap) {
    q->capacity = cap;
    q->front = 0;
    q->rear = 0;
    q->data = (struct Node**)malloc(cap * sizeof(struct Node*));
}
void NodeQueue_push(struct NodeQueue* q, struct Node* n) {
    q->data[q->rear++] = n;
}
struct Node* NodeQueue_pop(struct NodeQueue* q) {
    return q->data[q->front++];
}
struct Node* NodeQueue_front(struct NodeQueue* q) {
    return q->data[q->front];
}
int NodeQueue_empty(struct NodeQueue* q) {
    return q->front == q->rear;
}

struct createtree {
    struct Node *p, *t;
    int x;
    struct NodeQueue q;
};

int createtree_leafNodeCount_node(struct createtree* self, struct Node *p) {
    int x;
    int y;
    if (p != NULL){
        x = createtree_leafNodeCount_node(self, p->lchild);
        y = createtree_leafNodeCount_node(self, p->rchild);
        if (p->lchild == NULL && p->rchild == NULL){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int createtree_leafNodeCount(struct createtree* self) {
    return createtree_leafNodeCount_node(self, root);
}

int createtree_count_node(struct createtree* self, struct Node *p) {
    if(p != NULL)
        return createtree_count_node(self, p->lchild) + createtree_count_node(self, p->rchild) + 1;
    return 0;
}

int createtree_count(struct createtree* self) {
    return createtree_count_node(self, root);
}

int createtree_height_node(struct createtree* self, struct Node *p) {
    int x, y;
    if(p) {
        x = createtree_height_node(self, p->lchild);
        y = createtree_height_node(self, p->rchild);
        if(x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

int createtree_height(struct createtree* self) {
    return createtree_height_node(self, root);
}

void createtree_Levelorder(struct createtree* self) {
    struct NodeQueue q;
    init_NodeQueue(&q, 1000);
    struct Node *t = root;
    NodeQueue_push(&q, t);
    while(!NodeQueue_empty(&q)) {
        t = NodeQueue_front(&q);
        NodeQueue_pop(&q);
        printf("%d ", t->data);
        if(t->lchild) {
            NodeQueue_push(&q, t->lchild);
        }
        if(t->rchild) {
            NodeQueue_push(&q, t->rchild);
        }
    }
}

void init_createtree(struct createtree* self) {
    printf("Enter the root Node data  ");
    scanf("%d", &root->data);
    root->lchild = root->rchild = NULL;
    init_NodeQueue(&self->q, 1000);
    NodeQueue_push(&self->q, root);
    while(!NodeQueue_empty(&self->q)) {
        self->p = NodeQueue_front(&self->q);
        NodeQueue_pop(&self->q);
        printf("Enter the value of left child of %d ", self->p->data);
        scanf("%d", &self->x);
        if(self->x != -1) {
            self->t = (struct Node*)malloc(sizeof(struct Node));
            self->t->data = self->x;
            self->t->lchild = self->t->rchild = NULL;
            self->p->lchild = self->t;
            NodeQueue_push(&self->q, self->t);
        }
        printf("Enter the value of right child of  %d ", self->p->data);
        scanf("%d", &self->x);
        if(self->x != -1) {
            self->t = (struct Node*)malloc(sizeof(struct Node));
            self->t->data = self->x;
            self->t->lchild = self->t->rchild = NULL;
            self->p->rchild = self->t;
            NodeQueue_push(&self->q, self->t);
        }
    }
}

int main() {
    struct createtree t;
    init_createtree(&t);
    printf("\nleaf Node %d", createtree_leafNodeCount(&t));
    return 0;
}
