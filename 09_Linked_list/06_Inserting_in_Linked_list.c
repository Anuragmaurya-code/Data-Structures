#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

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


void insert(int pos ,int value)
{
    int i;
    struct Node * p;
    struct Node *t;
    if(pos<0 || pos>count(first))
    return ;

    p=first;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(pos==0)
    {
        t->data=value;
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        for(i=0;i<pos-1 && p;i++)//as it go to next node after one loop  and the node starts from 0
                                    //where as position starts from 1
        {
            p=p->next;
        }
        t->data=value;
        t->next=p->next;
        p->next=t;
    }
}
int main()
{
    int A[]={4,5,8,9,7};
    create(A,5);
    printf(" Before insert\n");
    Display();
    insert(2,78);

    printf(" After insert\n");
    Display();

    return 0;
}
