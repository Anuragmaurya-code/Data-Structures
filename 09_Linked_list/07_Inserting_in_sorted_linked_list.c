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

void S_Insert(struct Node *p,int value)
{
    struct Node *q = NULL;
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=value;
    t->next=NULL;

    if(first==NULL)
        first=t;
    else
    {
        while (p && p->data<value)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else{
            q->next=t;
            t->next=p;
        }
        
    }

}

int main()
{
    int A[]={4,7,9,12,18};
    create(A,5);
    S_Insert(first,8);
    Display();

    return 0;
}
