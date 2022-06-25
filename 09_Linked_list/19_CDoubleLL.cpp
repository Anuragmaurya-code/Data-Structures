#include<iostream>
#include<stdlib.h>
using namespace std;
class Node {
    public:
    Node *prev;
    int data;
    Node *next;
};
class CDoublyLL
{
private:
    Node *first=NULL;
public:
    CDoublyLL()
        {first=NULL;}
    CDoublyLL(int A[],int n);
    void Display();
    int Length();
    void Insert(int index,int x);
    int Delete(int index);
    ~CDoublyLL();

};
CDoublyLL::CDoublyLL(int A[],int n)
{
    Node *last,*t;
    first=new Node;
    first->data=A[0];
    first->next=first;
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
    first->prev=last;
    
}

void CDoublyLL::Display()
{
    Node *p=first;
    do
    {
        cout<<p->data<<"->";
        p=p->next;
    }while(p!=first);
    cout<<"\n";
}

int CDoublyLL::Length()
{
    Node *p=first;
    if(first==NULL)
        return 0;
    int x=0;
    do
    {
        ++x;
        p=p->next;
    }while(p!=first);
    return x;
}

int CDoublyLL::Delete(int index)
{
    if(index<0 || index>Length())
        return -1;

    Node *p=first;
    int x;

    if(index==1)
    {
        if(first->next)
        {
            first->prev->next=first->next;
            first=first->next;
            first->prev=p->prev;
            x=p->data;
        }
        else{
            first=NULL;
        }
        delete p;
        return x;
    }
    else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        x=p->data;
        delete p;
        return x;
    }
}
void CDoublyLL::Insert(int index,int x)
{
    if(index<0 || index>Length())
        return;
    Node *t,*p=first;
    t=new Node;
        t->data=x;
    if(index==0)//before first node
    {
        if(first)
        {
            t->next=first;
            t->prev=first->prev;
            t->prev->next=t;
            first->prev=t;
        }
        else{
            t->next=t->prev=t;
        }
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




CDoublyLL::~CDoublyLL()
{
    Node *p=first,*q;
    int len=Length();
    while(len>0)
    {
        q=p->next;
        cout<<"Deleted :"<<p->data<<endl;
        delete p;
        p=q;
        --len;
    }
}

int main()
{
    
    CDoublyLL a;
    a.Insert(0,3);
    a.Insert(1,7);
    a.Insert(2,4);
    cout<<"Before"<<endl;
    a.Display();
    cout<<"Before Length : "<<a.Length()<<endl; 

    cout<<"Deleted : "<<a.Delete(1)<<endl;

    cout<<"After"<<endl;
    a.Display();
    cout<<"AFter Length : "<<a.Length()<<endl;

    
    return 0;
}