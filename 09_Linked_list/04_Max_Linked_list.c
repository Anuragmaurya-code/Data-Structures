#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

int Max(struct Node * p)
{
    int max=-2147483648; // INT32_MIN equivalent
    while (p!=NULL)
    {
        if(max<p->data)
            max=p->data;
        p=p->next;
    }
    return max;
    
}

int RMax(struct Node * p)
{
    int x=0;
    if(p==0)
        return -2147483648;
    else
    {
        x=RMax(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
    }
    
    
}

int main()
{
    int A[]={4,5,78,8,94,7222};
    create(A,6);
    printf("%d\n", RMax(first));

    return 0;
}
