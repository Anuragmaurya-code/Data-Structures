#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct {
    struct Node *Head;
} CircularLinkedList;

void init_CircularLinkedList(CircularLinkedList *self) {
    self->Head = NULL;
}

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

int CircularLinkedList_length(CircularLinkedList *self) {
    struct Node *p = self->Head;
    int l = 0;
    if(self->Head == NULL) return 0;
    do {
        l++;
        p = p->next;
    } while(p != self->Head);
    return l;
}

void CircularLinkedList_insert(CircularLinkedList *self, int index, int value) {
    if(index < 0 || index > CircularLinkedList_length(self))
        return;
    struct Node *p = self->Head, *t;
    int i;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;
    if(index == 0) {
        if(self->Head == NULL) {
            t->next = t;
            self->Head = t;
        } else {
            while(p->next != self->Head)
                p = p->next;
            t->next = p->next;
            p->next = t;
        }
    } else {
        for(i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
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
    if(self->Head == NULL) return;
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
    printf("Before :");
    CircularLinkedList_display(&l);
    CircularLinkedList_insert(&l, 1, 2);
    printf("After : ");
    CircularLinkedList_display(&l);
    return 0;
}
