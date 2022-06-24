#include<iostream>

using namespace std;
class Node{
    public:
        int data;
        Node *next;
};

class LinkedList
{
private:
    Node *first;
public:
    LinkedList()
    {
        first=NULL;
    }
    LinkedList(int A[],int n);
    void display();
    int length();
    void insert(int pos ,int value);
    int del(int index);
    ~LinkedList();
    
};

LinkedList::~LinkedList()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}
int LinkedList::del(int index)
{
    Node *q=NULL,*p=first;
    int x=-1;//to store data of deleted node
    if(index<0 || index>length())
        return -1;
    if(index==0)
    {
        x=first->data;
        first=first->next;
    }
    else
    {
        for(int i=0;i<index;i++)
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
LinkedList::LinkedList(int A[],int n)
    {
        int i;
        Node *last, *t;
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
int LinkedList::length()//counting of nodes
{
    int c=0;
    Node *p;
    p=first;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}
void LinkedList::display()
{
    Node *p;
    p=first;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}
void LinkedList::insert(int pos ,int value)
{
    if(pos<0 || pos>length())
    return ;

    Node * p;
    Node *t;
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
    int A[]={1,6,8,12,56};
    LinkedList l(A,5);
   
    l.insert(2,67);

     l.display();

    cout<<"lenght "<<l.length()<<endl;


    l.del(1);
    cout<<"After deletion"<<endl;
    l.display();
    return  0;
}
