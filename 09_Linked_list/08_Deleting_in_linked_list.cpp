#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *last, *t;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;//addreess is passed and now first is refferd as last

    for(int i=1;i<n;i++)
    {
        t=new Node;
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
        cout<<p->data<<endl;
        p=p->next;
    }
}

int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
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
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        x=p->data;
        q->next=p->next;
    }

    delete p;
    return x;
}
int main()
{
    int A[]={4,7,9,12,18};
    create(A,5);
    cout<<"Deleted : "<<Delete(first,3)<<endl;
    Display();

    return 0;
}