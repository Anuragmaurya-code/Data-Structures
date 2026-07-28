#include <stdio.h>
#include <stdlib.h>
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
bool isloop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q->next!=NULL?q->next:NULL;
    } while (p && q && p!=q);
    
    return p==q?true:false;
}

int main()
{
    struct Node *p,*q;
    int A[]={4,7,19,12,15,18};
    create(A,6);   
    p=first->next->next;
    q=first->next->next->next->next->next;
    q->next=p;
    if(isloop(first))
    {
        printf("there\'s  a loop");
    }
    else
        printf("Theres not  a loop");
   

    return 0;
}
