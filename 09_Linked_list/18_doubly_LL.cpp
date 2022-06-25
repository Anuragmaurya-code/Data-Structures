#include<iostream>
#include<stdlib.h>
using namespace std;
class Node {
    public:
    Node *prev;
    int data;
    Node *next;
};
class DoublyLL
{
private:
    Node *first=NULL;
public:
    DoublyLL(int A[],int n);
    void Display();
    int Length();
    void Insert(int index,int x);
    int Delete(int index);
    void Reverse();
    ~DoublyLL();

};
void DoublyLL::Reverse()
{
    Node *temp,*p=first;
    while(p)
    {
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        p=p->prev;
        if(p && p->next==NULL)//
            first=p;
    }
}
int DoublyLL::Delete(int index)
{
    if(index<0 || index>Length())
        return -1;

    Node *p=first;
    int x;

    if(index==1)
    {
        first=first->next;
        x=p->data;
        delete p;
        if(first)
            first->prev=NULL;
        return x;
    }
    else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        delete p;
        return x;
    }
}
void DoublyLL::Insert(int index,int x)
{
    if(index<0 || index>Length())
        return;
    Node *t,*p=first;
    t=new Node;
        t->data=x;
    if(index==0)//before first node
    {
        t->next=first;
        t->prev=NULL;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        if(p->next) 
            p->next->prev=t;
        p->next=t;
        t->prev=p;
    }
}
int DoublyLL::Length()
{
    Node *p=first;
    int x=0;
    while(p)
    {
        ++x;
        p=p->next;
    }
    return x;
}
void DoublyLL::Display()
{
    Node *p=first;
    while(p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"\n";
}
DoublyLL::DoublyLL(int A[],int n)
{
    Node *last,*t;
    first=new Node;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->next=last->next;
        t->data=A[i];
        t->prev=last;
        last->next=t;
        last=t;
    }
    
}

DoublyLL::~DoublyLL()
{
    Node *p=first,*q;
    while(p)
    {
        q=p;
        p=p->next;
        cout<<"\n"<<"Deleted :"<<q->data;
        delete q;
    }
}

int main()
{
    int A[]={1,4,6,7,9};
    DoublyLL a(A,5);
    cout<<"Before "<<endl;
    a.Display();
    a.Reverse();
    cout<<"After "<<endl;
    a.Display();
    cout<<"\nLength : "<<a.Length();
    return 0;
}