#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create1(int A[],int n)
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
void create2(int A[],int n)
{
    int i;
    struct Node *last, *t;
    second=new Node;
    second->data=A[0];
    second->next=NULL;
    last=second;//addreess is passed and now first is refferd as last

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;//putting address of current node in the next of last node 
        last=t;//assigning current node as last node
    }
}

void Display(struct Node *p)
{

    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}


void Concatenate(struct Node *p,struct Node *q) 
{
    third=p;
    while(p->next)
        p=p->next;
    p->next=q;
}

void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data< q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while (p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
        last->next=p;
    else
        last->next=q;
    
}
int main()
{
    int A[]={4,7,17,21,25,30};
    int B[]={5,15,19,23,27,34,37};
    create1(A,6);
    cout<<"First"<<endl;
    Display(first);
    create2(B,7);
    cout<<"second "<<endl;
    Display(second);    
    cout<<"third"<<endl;
    Merge(first,second);
    Display(third);
    

    return 0;
}