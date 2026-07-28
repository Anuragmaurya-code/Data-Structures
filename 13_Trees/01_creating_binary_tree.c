#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Queue.h"

struct createtree {
    struct Node *p, *t;
    int x;
    struct Queue q;
};

void init_createtree(struct createtree* self) {
    printf("Enter the root Node data  ");
    scanf("%d", &root->data);
    root->lchild = root->rchild = NULL;
    // Assuming create is not explicitly required based on original or is initialized elsewhere
    enqueue(&self->q, root);
    while(!isEmpty(&self->q)) {
        self->p = dequeue(&self->q);
        printf("Enter the value of left child of %d ", self->p->data);
        scanf("%d", &self->x);
        if(self->x != -1) {
            self->t = (struct Node*)malloc(sizeof(struct Node));
            self->t->data = self->x;
            self->t->lchild = self->t->rchild = NULL;
            self->p->lchild = self->t;
            enqueue(&self->q, self->t);
        }
        printf("Enter the value of right child of  %d ", self->p->data);
        scanf("%d", &self->x);
        if(self->x != -1) {
            self->t = (struct Node*)malloc(sizeof(struct Node));
            self->t->data = self->x;
            self->t->lchild = self->t->rchild = NULL;
            self->p->rchild = self->t;
            enqueue(&self->q, self->t);
        }
    }
}

void createtree_display(struct createtree* self) {
    struct Node *t;
    struct Queue q;
    enqueue(&q, root);
    while(!isEmpty(&q)) {
        t = dequeue(&q);
        printf("%d ", t->data);
        if(t->lchild)
            enqueue(&q, t->lchild);
        if(t->rchild)
            enqueue(&q, t->rchild);
    }
}

int main() {
    struct createtree r;
    init_createtree(&r);
    createtree_display(&r);
    return 0;
}
