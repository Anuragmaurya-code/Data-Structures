#include<stdio.h>
#include<stdlib.h>
struct matrix{ //structure of matrix
    int n;
    int *A;
};
void set(struct matrix *a,int i,int j,int x)//set for row major mapping
{
    
    if(i>=j)
    {
        int t=((i*(i-1)/2)+(j-1));// it means sum of i-1 rows then   the jth element in matrix 
        a->A[t]=x;
    }

}

int get(struct matrix *a,int i,int j)//get for row major mapping
{
    
    if(i>=j)
    {
        int t=((i*(i-1)/2)+(j-1));
        return a->A[t];
    }
    else
        return 0;
}
void Display(struct matrix *a)//Display for row major mapping
{
    for(int i=1;i<=(a->n);i++)//here  i is considered as matrix index so is started from 1
    {
        for(int j=1;j<=(a->n);j++)
        {
            if(i>=j)
            {
                int t=((i*(i-1)/2)+(j-1));
                printf("%d ",a->A[t]);
            }
            else
            printf("%d ",0);
        }
        printf("\n");
    }
}
void cset(struct matrix *a,int i,int j,int x)//set for column major mapping
{   
    if(i>=j)
    {
        if(i>=j)
        {
            a->A[a->n*(j-1)-(j-1)*(j-2)/2+(i-j)]=x;
        }

    }

}

int cget(struct matrix *a,int i,int j)//get for column major mapping
{
    
    if(i>=j)
    {
        return a->A[a->n*(j-1)-(j-1)*(j-2)/2+(i-j)];
    }
    else
        return 0;
}
void cDisplay(struct matrix *a)//Display column major mapping
{
    for(int i=1;i<=(a->n);i++)//here  i is considered as matrix index so is started from 1
    {
        for(int j=1;j<=(a->n);j++)
        {
            if(i>=j)
            {
                printf("%d ",a->A[a->n*(j-1)-(j-1)*(j-2)/2+(i-j)]);
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
    struct matrix m;
    printf("Enter number dimension of matrix ");
    scanf("%d",&num);
    m.n=num;
    m.A=(int *)malloc((m.n*(m.n+1)/2)*sizeof(int));//as it contains this many number of elements
    printf("Enter the elements ");
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            scanf("%d",&x);
            set(&m,i,j,x);
        }
    }
    
    Display(&m);
    printf("\n\n");


    //using column major formula
    printf("Enter number of elements ");
    scanf("%d",&num);
    m.n=num;
    m.A=(int *)malloc((m.n*(m.n+1)/2)*sizeof(int));
    printf("Enter the elements ");
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            scanf("%d",&x);
            cset(&m,i,j,x);
        }
    }
    
    cDisplay(&m);
    
    return 0;
}