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
        cout<<"there\'s  a loop";
    }
    else
        cout<<"Theres not  a loop";
   

    return 0;
}