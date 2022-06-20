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

struct Node *Linear_Search(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if(p->data == key)
            return p;
        p=p->next;

    }
    return NULL;
}

struct Node *RLinear_Search(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    else if(p->data == key)
        return p;
    else
        return RLinear_Search(p->next,key);

}

struct Node *ILinear_Search(struct Node *p,int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(p->data == key)
        {
            if(p==first)//  very  important as in case if the first element is same to key there
                        // wont be any value to q 
                return p;
            else
            {
            q->next=p->next;
            p->next=first;
            first=p;
            }
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}


int main()
{
    int A[]={4,5,8,9,7};
    create(A,5);
    struct Node *temp;
    temp=ILinear_Search(first,8);
    if(temp)
        cout<<"Key founded  "<<temp->data<<endl;
    else
        cout<<"Key not found"<<endl;
    Display();
    return 0;
}