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
        last->next=t; //putting address of current node in the next of last node 
        last=t; //assigning current node as last node
    }
}

void Display(struct Node *p) //display using recurssion
{
    if(p!=NULL)
    {
        cout<<p->data<<endl;
    }
    Display(p->next);
}
void RDisplay(struct Node *p)// reverse display using recurssion
{
    if(p!=NULL)
    {
        RDisplay(p->next);
        cout<<p->data<<endl;
    }
    
}

int main()
{
    int A[]={4,5,8,9,7};
    create(A,5);
    RDisplay(first);

    return 0;
}