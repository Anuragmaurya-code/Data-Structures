#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

typedef struct {
    struct Node *first;
} CDoublyLL;

void init_CDoublyLL(CDoublyLL *self) {
    self->first = NULL;
}

void init_CDoublyLL_Array(CDoublyLL *self, int A[], int n) {
    struct Node *last, *t;
    int i;
    self->first = (struct Node*)malloc(sizeof(struct Node));
    self->first->data = A[0];
    self->first->next = self->first;
    last = self->first;
    for(i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->next = last->next;
        t->data = A[i];
        t->prev = last;
        last->next = t;
        last = t;
    }
    self->first->prev = last;
}

void CDoublyLL_Display(CDoublyLL *self) {
    struct Node *p = self->first;
    if(self->first == NULL) return;
    do {
        printf("%d->", p->data);
        p = p->next;
    } while(p != self->first);
    printf("\n");
}

int CDoublyLL_Length(CDoublyLL *self) {
    struct Node *p = self->first;
    if(self->first == NULL)
        return 0;
    int x = 0;
    do {
        ++x;
        p = p->next;
    } while(p != self->first);
    return x;
}

int CDoublyLL_Delete(CDoublyLL *self, int index) {
    if(index < 0 || index > CDoublyLL_Length(self))
        return -1;
    struct Node *p = self->first;
    int x, i;
    if(index == 1) {
        if(self->first->next) {
            self->first->prev->next = self->first->next;
            self->first = self->first->next;
            self->first->prev = p->prev;
            x = p->data;
        } else {
            self->first = NULL;
        }
        free(p);
        return x;
    } else {
        for(i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        x = p->data;
        free(p);
        return x;
    }
}

void CDoublyLL_Insert(CDoublyLL *self, int index, int x) {
    if(index < 0 || index > CDoublyLL_Length(self))
        return;
    struct Node *t, *p = self->first;
    int i;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0) {
        if(self->first) {
            t->next = self->first;
            t->prev = self->first->prev;
            t->prev->next = t;
            self->first->prev = t;
        } else {
            t->next = t->prev = t;
        }
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

void destroy_CDoublyLL(CDoublyLL *self) {
    struct Node *p = self->first, *q;
    int len = CDoublyLL_Length(self);
    while(len > 0) {
        q = p->next;
        printf("Deleted :%d\n", p->data);
        free(p);
        p = q;
        --len;
    }
}

int main() {
    CDoublyLL a;
    init_CDoublyLL(&a);
    CDoublyLL_Insert(&a, 0, 3);
    CDoublyLL_Insert(&a, 1, 7);
    CDoublyLL_Insert(&a, 2, 4);
    printf("Before\n");
    CDoublyLL_Display(&a);
    printf("Before Length : %d\n", CDoublyLL_Length(&a)); 

    printf("Deleted : %d\n", CDoublyLL_Delete(&a, 1));

    printf("After\n");
    CDoublyLL_Display(&a);
    printf("AFter Length : %d\n", CDoublyLL_Length(&a));

    destroy_CDoublyLL(&a);
    return 0;
}
