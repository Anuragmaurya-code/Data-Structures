#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

typedef struct {
    struct Node *first;
} DoublyLL;

void init_DoublyLL_Array(DoublyLL *self, int A[], int n) {
    struct Node *last, *t;
    int i;
    self->first = (struct Node*)malloc(sizeof(struct Node));
    self->first->data = A[0];
    self->first->prev = self->first->next = NULL;
    last = self->first;
    for(i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->next = last->next;
        t->data = A[i];
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void DoublyLL_Display(DoublyLL *self) {
    struct Node *p = self->first;
    while(p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
}

int DoublyLL_Length(DoublyLL *self) {
    struct Node *p = self->first;
    int x = 0;
    while(p) {
        ++x;
        p = p->next;
    }
    return x;
}

void DoublyLL_Insert(DoublyLL *self, int index, int x) {
    if(index < 0 || index > DoublyLL_Length(self))
        return;
    struct Node *t, *p = self->first;
    int i;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0) {
        t->next = self->first;
        t->prev = NULL;
        self->first = t;
    } else {
        for(i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        if(p->next) 
            p->next->prev = t;
        p->next = t;
        t->prev = p;
    }
}

int DoublyLL_Delete(DoublyLL *self, int index) {
    if(index < 0 || index > DoublyLL_Length(self))
        return -1;
    struct Node *p = self->first;
    int x, i;
    if(index == 1) {
        self->first = self->first->next;
        x = p->data;
        free(p);
        if(self->first)
            self->first->prev = NULL;
        return x;
    } else {
        for(i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
        return x;
    }
}

void DoublyLL_Reverse(DoublyLL *self) {
    struct Node *temp, *p = self->first;
    while(p) {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
        if(p && p->next == NULL)
            self->first = p;
    }
}

void destroy_DoublyLL(DoublyLL *self) {
    struct Node *p = self->first, *q;
    while(p) {
        q = p;
        p = p->next;
        printf("\nDeleted :%d", q->data);
        free(q);
    }
}

int main() {
    int A[] = {1, 4, 6, 7, 9};
    DoublyLL a;
    init_DoublyLL_Array(&a, A, 5);
    printf("Before \n");
    DoublyLL_Display(&a);
    DoublyLL_Reverse(&a);
    printf("After \n");
    DoublyLL_Display(&a);
    printf("\nLength : %d\n", DoublyLL_Length(&a));
    destroy_DoublyLL(&a);
    return 0;
}
