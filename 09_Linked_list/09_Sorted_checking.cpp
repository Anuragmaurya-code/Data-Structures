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

bool isSorted(struct Node *p)
{
    int n=INT32_MIN;
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
    cout<<"Sorted : "<<isSorted(first)<<endl;
    Display();

    return 0;
}