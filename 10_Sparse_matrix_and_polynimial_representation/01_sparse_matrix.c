#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row;
    int column;
    int value;
    struct Node *next;
} Node;

typedef struct Sparse_Matrix {
    Node *first;
    int m, n;
} Sparse_Matrix;

void init_Sparse_Matrix(Sparse_Matrix* self) {
    self->first = NULL;
    int i, j, data;
    printf("Enter the dimension of Matrix ");
    scanf("%d%d", &self->m, &self->n);
    Node *p = NULL, *q = NULL;
    printf("Enter the Matrix: \n");

    for(i = 0; i < self->m; i++) {
        for(j = 0; j < self->n; j++) {
            scanf("%d", &data);
            if(data != 0) {
                p = (Node*)malloc(sizeof(Node));
                if(q != NULL)
                    q->next = p;
                else
                    self->first = p;
                p->value = data;
                p->row = i;
                p->column = j;
                p->next = NULL;
                q = p;
            }
        }
    }
}

Node* Sparse_Matrix_GetHead(Sparse_Matrix* self) {
    return self->first;
}

void Sparse_Matrix_Merge(Sparse_Matrix* self, Sparse_Matrix b) {
    Node *first1 = self->first, *first2 = Sparse_Matrix_GetHead(&b), *first3 = NULL, *p = NULL, *q = NULL;
    while (first1 && first2) {
        if(first1->row < first2->row) {
            p = first1;
            if(q)
                q->next = p;
            else
                first3 = p;
            q = p;
            first1 = first1->next;
            p->next = NULL;
        }
        else if(first2->row < first1->row) {
            p = first2;
            if(q)
                q->next = p;
            else
                first3 = p;
            q = p;
            first2 = first2->next;
            p->next = NULL;
        }
        else {   
            if(first1->column < first2->column) {
                p = first1;
                if(q)
                    q->next = p;
                else
                    first3 = p;
                q = p;
                first1 = first1->next;
                p->next = NULL;
            }
            else if(first2->column < first1->column) {
                p = first2;
                if(q)
                    q->next = p;
                else
                    first3 = p;
                q = p;
                first2 = first2->next;
                p->next = NULL;
            }
            else {
                p = first1;
                if(q)
                    q->next = p;
                else
                    first3 = p;
                q = p;
                p->value = first1->value + first2->value;
                first1 = first1->next;
                Node *temp = first2;
                first2 = first2->next;
                temp->next = NULL;
                p->next = NULL;
            }
        }
    }
    if(first1)
        p->next = first1;
    else
        p->next = first2;
    self->first = first3;
}

void Sparse_Matrix_Display(Sparse_Matrix* self) {
    Node *p = NULL;
    p = self->first;
    for(int i = 0; i < self->m; i++) {
        for(int j = 0; j < self->n; j++) {   
            if(p && p->row == i && p->column == j) {
                printf("%d ", p->value);
                p = p->next;
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    Sparse_Matrix a;
    Sparse_Matrix b;

    init_Sparse_Matrix(&a);
    init_Sparse_Matrix(&b);

    Sparse_Matrix_Merge(&a, b);
    Sparse_Matrix_Display(&a);
    return 0;
}
