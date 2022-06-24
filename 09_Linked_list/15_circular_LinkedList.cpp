#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
};

class CircularLinkedList{
    private:
        Node *Head;
    public:
    CircularLinkedList(int A[],int n);
    Node * getHead(){return Head;}
    void display();
    void Rdisplay(Node *p);
};
void CircularLinkedList::Rdisplay(Node *p)
{
    static int flag=0;
    if(p!=Head || flag==0)
    {
        flag=1;
        cout<<p->data<<"->";
        Rdisplay(p->next);
    }
    flag=0;
}
void CircularLinkedList::display()
{
    Node *p=Head;
    do{
        cout<<p->data<<"->";
        p=p->next;

    }while(p!=Head);
    cout<<endl;
}
CircularLinkedList::CircularLinkedList(int A[],int n)
{
    Node *last,*t;
    
    Head=new Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

int main()
{
    
    int A[]={1,3,5,8,9};

    CircularLinkedList l(A,5);
    l.display();
    Node *h=l.getHead();
    l.Rdisplay(h);
    return 0;
}
