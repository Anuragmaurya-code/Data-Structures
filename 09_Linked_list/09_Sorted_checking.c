#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

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
        last->next=t;//putting address of current node in the next of last node 
        last=t;//assigning current node as last node
    }
}

void Display()
{
    struct Node *p;
    p=first;
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p=p->next;
    }
}

bool isSorted(struct Node *p)
{
    int n=-2147483648; // INT32_MIN equivalent
    while(p!=NULL)
    {
        if(p->data<n)
            return false;
        n=p->data;
        p=p->next;
    }
    return true;
}

int main()
{
    int A[]={4,7,19,12,18};
    create(A,5);
    printf("Sorted : %d\n", isSorted(first));
    

    return 0;
}
