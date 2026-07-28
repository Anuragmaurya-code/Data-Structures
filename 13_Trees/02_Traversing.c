//Mine not working  becz of some fault
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"

struct createtree {
    struct Node *p, *t;
    int x;
    struct Queue q;
};

void createtree_rinorder(struct createtree* self, struct Node *t) {
    if(t) {
        createtree_rinorder(self, t->lchild);
        printf("%d ", t->data);
        createtree_rinorder(self, t->rchild);
    }
}

void createtree_inorder(struct createtree* self) {
    struct Stack st;
    create(&st);
    long int num;
    struct Node *t = root;
    while(t || !isEmpty(st)) {
        if(t != NULL) {
            push(&st, (long int)t); // storing address in long int
            t = t->lchild;
        } else {
            num = pop(&st);
            t = (struct Node *)num; // long int to address
            printf("%d ", t->data);
            t = t->rchild;
        }
    }
}

void createtree_preorder(struct createtree* self) {
    struct Stack st;
    create(&st);
    long int num;
    struct Node *t = root;
    while(t || !isEmpty(st)) {
        if(t != NULL) {
            push(&st, (long int)t);
            printf("%d ", t->data);
            t = t->lchild;
        } else {
            num = pop(&st);
            t = (struct Node *)num;
            t = t->rchild;
        }
    }
}

void createtree_postorder(struct createtree* self) {
    struct Stack st;
    create(&st);
    long int num;
    struct Node *t = root;
    while(t || !isEmpty(st)) {
        if(t != NULL) {
            push(&st, (long int)t);
            t = t->lchild;
        } else {
            num = pop(&st);
            if(num > 0) {
                push(&st, -1 * num);
                t = ((struct Node *)num)->rchild;
            } else {
                printf("%d ", ((struct Node *)(-1 * num))->data);
                t = NULL;
            }
        }
    }
}

void createtree_display(struct createtree* self) {
    struct Node *t;
    struct Queue q;
    enqueue(&q, root);
    while(!isEmpty(q)) { // Using what matched the original Stack isEmpty parameter signature
        t = dequeue(&q);
        printf("%d ", t->data);
        if(t->lchild)
            enqueue(&q, t->lchild);
        if(t->rchild)
            enqueue(&q, t->rchild);
    }
}

void init_createtree(struct createtree* self) {
    printf("Enter the root Node data  ");
    scanf("%d", &root->data);
    root->lchild = root->rchild = NULL;
    enqueue(&self->q, root);
    while(!isEmpty(self->q)) {
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

int main() {
    struct createtree r;
    init_createtree(&r);
    createtree_inorder(&r);
    return 0;
}
