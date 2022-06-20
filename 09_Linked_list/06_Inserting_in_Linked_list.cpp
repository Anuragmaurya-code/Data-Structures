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


void insert(int pos ,int value)
{
    struct Node *p;
    struct Node *t;
    p=first;
    t=new Node;
    if(pos==0)
    {
        t->data=value;
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        for(int i=0;i<pos-1 && p;i++)//as it go to next node after one loop  and the node starts from 0
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
    cout<< " Before insert"<<endl;
    Display();
    insert(3,8);

    cout<< " After insert"<<endl;
    Display();

    return 0;
}