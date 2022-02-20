#include<stdio.h>
struct matrix
{
    int n;
    int A[10];
};
void set(struct matrix *a,int i,int j,int x)
{
    if(i==j)
    {
        a->A[i-1]=x;
    }

}
int get(struct matrix *a,int i,int j)
{
    if(i==j)
        a->A[i-1];
    else
        return 0;
}
void Display(struct matrix *a)
{
    for(int i=0;i<(a->n);i++)
    {
        for(int j=0;j<(a->n);j++)
        {
            if(i==j)
            printf("%d ",a->A[i]);
            else
            printf("%d ",0);
        }
        printf("\n");
    }
}
int main()
{
    struct matrix m;
    m.n=4;
    set(&m,1,1,7);
    set(&m,2,2,5);
    set(&m,3,3,6);
    set(&m,4,4,3);
    Display(&m);

    return 0;
}