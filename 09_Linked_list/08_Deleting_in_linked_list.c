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

int count(struct Node *p)//counting of nodes
{
    int c=0;
    
    p=first;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
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

int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int i;
    int x=-1;//to store data of deleted node
    if(index<0 || index>count(p))
        return -1;
    if(index==1)
    {
        x=first->data;
        first=first->next;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        x=p->data;
        q->next=p->next;
    }

    free(p);
    return x;
}
int main()
{
    int A[]={4,7,9,12,18};
    create(A,5);
    printf("Deleted : %d\n", Delete(first,3));
    Display();

    return 0;
}
