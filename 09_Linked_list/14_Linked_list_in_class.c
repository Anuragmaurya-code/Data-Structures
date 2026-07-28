#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct {
    struct Node *first;
} LinkedList;

void init_LinkedList(LinkedList *self) {
    self->first = NULL;
}

void init_LinkedList_Array(LinkedList *self, int A[], int n) {
    int i;
    struct Node *last, *t;
    self->first = (struct Node*)malloc(sizeof(struct Node));
    self->first->data = A[0];
    self->first->next = NULL;
    last = self->first;
    for(i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int LinkedList_length(LinkedList *self) {
    int c = 0;
    struct Node *p = self->first;
    while(p) {
        c++;
        p = p->next;
    }
    return c;
}

void LinkedList_display(LinkedList *self) {
    struct Node *p = self->first;
    while(p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void LinkedList_insert(LinkedList *self, int pos, int value) {
    if(pos < 0 || pos > LinkedList_length(self)) return;
    struct Node *p = self->first;
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(pos == 0) {
        t->data = value;
        t->next = self->first;
        self->first = t;
    } else if (pos > 0) {
        for(int i = 0; i < pos - 1 && p; i++) {
            p = p->next;
        }
        t->data = value;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList_del(LinkedList *self, int index) {
    struct Node *q = NULL, *p = self->first;
    int x = -1;
    if(index < 0 || index > LinkedList_length(self)) return -1;
    if(index == 0) {
        x = self->first->data;
        self->first = self->first->next;
    } else {
        for(int i = 0; i < index; i++) {
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
    }
    free(p);
    return x;
}

void destroy_LinkedList(LinkedList *self) {
    struct Node *p = self->first;
    while(self->first) {
        self->first = self->first->next;
        free(p);
        p = self->first;
    }
}

int main() {
    int A[] = {1, 6, 8, 12, 56};
    LinkedList l;
    init_LinkedList_Array(&l, A, 5);
   
    LinkedList_insert(&l, 2, 67);

    LinkedList_display(&l);

    printf("lenght %d\n", LinkedList_length(&l));

    LinkedList_del(&l, 1);
    printf("After deletion\n");
    LinkedList_display(&l);
    
    destroy_LinkedList(&l);
    return 0;
}
