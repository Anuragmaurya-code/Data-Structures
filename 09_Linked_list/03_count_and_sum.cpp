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
void count()//counting of nodes
{
    int c=0;
    struct Node *p;
    p=first;
    while(p)
    {
        c++;
        p=p->next;
    }
    cout<<" Count is "<<c<<endl;
}
int Rcount(struct Node *p)//recursive counting of nodes
{
    if(p)
        return Rcount(p->next)+1;
    return 0;
}
void sum()// sum of data of nodes
{
    int s=0;
    struct Node *p;
    p=first;
    while(p)
    {
        s=s+p->data;
        p=p->next;
    }
    cout<<" sum is "<<s<<endl;
}
int Rsum(struct Node *p)// recursive sum of data of nodes
{
    if(p)
        return p->data+Rsum(p->next);
    return 0;
}

int main()
{
    int A[]={4,5,8,9,7,1,9,4,7};
    create(A,9);
    count();
    cout<<"count is : "<<Rcount(first)<<endl;
    sum();
    cout<<"sum  is : "<<Rsum(first)<<endl;
    return 0;
}