#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *A;
} Matrix;

void init_Matrix(Matrix* self, int n)
{
    self->n=n;
    self->A=(int*)malloc(n * sizeof(int));   
}

void destroy_Matrix(Matrix* self)
{
    free(self->A);
}

void Matrix_set(Matrix* self, int i,int j,int x)
{
    if(i==j)
    {
        self->A[i-1]=x;
    }
}

int Matrix_get(Matrix* self, int i,int j)
{
    if(i==j)
        return self->A[i-1];
    else
        return 0;
}

void Matrix_Display(Matrix* self)
{
    for(int i=0;i<(self->n);i++)
    {
        for(int j=0;j<(self->n);j++)
        {
            if(i==j)
            printf("%d ", self->A[i]);
            else
            printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    Matrix m;
    init_Matrix(&m, 3);
    Matrix_set(&m, 1,1,4);
    Matrix_set(&m, 2,2,5);
    Matrix_set(&m, 3,3,6);
    Matrix_Display(&m);
    printf("%d\n", Matrix_get(&m, 3,3));
    
    destroy_Matrix(&m);

    return 0;
}
