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

void reverse1(struct Node *p)//Reverse using (Auxiliary)array
{
    int *A,i=0;
    struct Node *q;
    A=(int*)malloc(count(p)*sizeof(int));
    q=p;
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
    free(A);
}

void reverse2(struct Node *p)//reversing by reversing the links
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;//make first the q as links are reveresed at q is at the last node after loop
}

void reverse3(struct Node *q,struct Node *p)
{
    if(p!=NULL)
    {
        reverse3(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
    }
}



int main()
{
    int A[]={4,7,19,12,15,18};
    create(A,6);
    printf("Before\n");
    Display();
    reverse3(NULL,first);
    printf("After\n");
    Display();    

    

    return 0;
}
