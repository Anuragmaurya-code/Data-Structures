#include<iostream>
#include<stdlib.h>
#include"Node.h"
#include"Queue.h"
using namespace std;

class createtree
{
    public:
    Node *p,*t;
    int x;
    Queue q;
   
    createtree()
    {   
        cout<<"Enter the root Node data  ";
        cin>>root->data;
        root->lchild=root->rchild=NULL;
        q.enqueue(root);
        while(!q.isEmpty())
        {
            p=q.dequeue();
            cout<<"Enter the value of left child of "<<p->data<<" ";
            cin>>x;
            if(x!=-1)
            {
                t=new Node;
                t->data=x;
                t->lchild=t->rchild=nullptr;
                p->lchild=t;
                q.enqueue(t);
            }
            cout<<"Enter the value of right child of  "<<p->data<<" ";
            cin>>x;
            if(x!=-1)
            {
                t=new Node;
                t->data=x;
                t->lchild=t->rchild=nullptr;
                p->rchild=t;
                q.enqueue(t);
            }

        }
    }

    void display()
    {
        Node *t;
        Queue q;
        q.enqueue(root);
        while(!q.isEmpty())
        {
            t=q.dequeue();
            cout<<t->data<<" ";
            if(t->lchild)
                q.enqueue(t->lchild);
            if(t->rchild)
                q.enqueue(t->rchild);
        
        }

    }
};

int main()
{
    createtree r;
    r.display();
    return 0;

}