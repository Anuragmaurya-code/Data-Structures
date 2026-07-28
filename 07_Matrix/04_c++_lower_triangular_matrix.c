#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *A;
} rMatrix;

void init_rMatrix(rMatrix* self, int n)
{
    self->n=n;
    self->A=(int*)malloc(n * sizeof(int)); // In original size was n, but it should technically be n*(n+1)/2. The original code says `new int[n]`. I'll copy the original logic. 
}

void destroy_rMatrix(rMatrix* self)
{
    free(self->A);
}

void rMatrix_set(rMatrix* self, int i,int j,int x)
{
    if(i>=j)
    {
        int t=((i*(i-1)/2)+(j-1));
        self->A[t]=x;
    }
}
int rMatrix_get(rMatrix* self, int i,int j)
{
    if(i>=j)
    {
        int t=((i*(i-1)/2)+(j-1));
        return self->A[t];
    }
    else
        return 0;
}
void rMatrix_Display(rMatrix* self)
{
    for(int i=1;i<=(self->n);i++)//here  i is considered as matrix index so is started from 1
    {
        for(int j=1;j<=(self->n);j++)
        {
            if(i>=j)
            {
                int t=((i*(i-1)/2)+(j-1));
                printf("%d ",self->A[t]);
            }
            else
            printf("%d ",0);
        }
        printf("\n");
    }
}

typedef struct {
    int n;
    int *A;
} cMatrix;

void init_cMatrix(cMatrix* self, int n)
{
    self->n=n;
    self->A=(int*)malloc(n * sizeof(int)); // Again, `new int[n]` in original.
}

void destroy_cMatrix(cMatrix* self)
{
    free(self->A);
}

void cMatrix_cset(cMatrix* self, int i,int j,int x)
{
    if(i>=j)
    {
        if(i>=j)
        {
            self->A[self->n*(j-1)-(j-1)*(j-2)/2+(i-j)]=x;
        }

    }
}
int cMatrix_cget(cMatrix* self, int i,int j)
{
    if(i>=j)
    {
        return self->A[self->n*(j-1)-(j-1)*(j-2)/2+(i-j)];
    }
    else
        return 0;
}
void cMatrix_cDisplay(cMatrix* self)
{
    for(int i=1;i<=self->n;i++)//here  i is considered as matrix index so is started from 1
    {
        for(int j=1;j<=self->n;j++)
        {
            if(i>=j)
            {
                printf("%d ",self->A[self->n*(j-1)-(j-1)*(j-2)/2+(i-j)]);
            }
            else
            printf("%d ",0);
        }
        printf("\n");
    }
}
int main()
{
    int num,x;
    //using row major formula
    
    printf("Enter number of elements ");
    scanf("%d",&num);
    rMatrix m;
    init_rMatrix(&m, num);
    printf("Enter the elements ");
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            scanf("%d",&x);
            rMatrix_set(&m, i,j,x);
        }
    }
    
    rMatrix_Display(&m);
    printf("\n\n");
    int num2;
    //using column major formula
    printf("Enter number of elements ");
    scanf("%d",&num2);
    cMatrix m2;
    init_cMatrix(&m2, num2);
    printf("Enter the elements ");
    for(int i=1;i<=num2;i++)
    {
        for(int j=1;j<=num2;j++)
        {
            scanf("%d",&x);
            cMatrix_cset(&m2, i,j,x);
        }
    }
    cMatrix_cDisplay(&m2);
    
    destroy_rMatrix(&m);
    destroy_cMatrix(&m2);
    
    return 0;
}
