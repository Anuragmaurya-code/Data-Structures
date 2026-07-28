#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *last, *t;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;//addreess is passed and now first is refferd as last

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t; //putting address of current node in the next of last node 
        last=t; //assigning current node as last node
    }
}

void count()//counting of nodes
{
    int c=0;
    struct Node *p;
    p=first;
    while(p)
    {
        c++;
        p=p->next;
    }
    printf(" Count is %d\n", c);
}

int Rcount(struct Node *p)//recursive counting of nodes
{
    if(p)
        return Rcount(p->next)+1;
    return 0;
}

void sum()// sum of data of nodes
{
    int s=0;
    struct Node *p;
    p=first;
    while(p)
    {
        s=s+p->data;
        p=p->next;
    }
    printf(" sum is %d\n", s);
}

int Rsum(struct Node *p)// recursive sum of data of nodes
{
    if(p)
        return p->data+Rsum(p->next);
    return 0;
}

int main()
{
    int A[]={4,5,8,9,7,1,9,4,7};
    create(A,9);
    count();
    printf("count is : %d\n", Rcount(first));
    sum();
    printf("sum  is : %d\n", Rsum(first));
    return 0;
}
