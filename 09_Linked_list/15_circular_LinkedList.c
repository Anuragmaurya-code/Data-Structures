#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct {
    struct Node *Head;
} CircularLinkedList;

void init_CircularLinkedList_Array(CircularLinkedList *self, int A[], int n) {
    struct Node *last, *t;
    int i;
    self->Head = (struct Node*)malloc(sizeof(struct Node));
    self->Head->data = A[0];
    self->Head->next = self->Head;
    last = self->Head;
    for(i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

struct Node* CircularLinkedList_getHead(CircularLinkedList *self) {
    return self->Head;
}

void CircularLinkedList_Rdisplay(CircularLinkedList *self, struct Node *p) {
    static int flag = 0;
    if(p != self->Head || flag == 0) {
        flag = 1;
        printf("%d->", p->data);
        CircularLinkedList_Rdisplay(self, p->next);
    }
    flag = 0;
}

void CircularLinkedList_display(CircularLinkedList *self) {
    struct Node *p = self->Head;
    do {
        printf("%d->", p->data);
        p = p->next;
    } while(p != self->Head);
    printf("\n");
}

int main() {
    int A[] = {1, 3, 5, 8, 9};

    CircularLinkedList l;
    init_CircularLinkedList_Array(&l, A, 5);
    CircularLinkedList_display(&l);
    struct Node *h = CircularLinkedList_getHead(&l);
    CircularLinkedList_Rdisplay(&l, h);
    return 0;
}
