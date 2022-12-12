//Mine not working  becz of some fault
#include<iostream>
#include<stdlib.h>
using namespace std;
#include"Node.h"
#include"Queue.h"
#include"Stack.h"


class createtree
{
    public:
    Node *p,*t;
    int x;
    Queue q;
    createtree();
    void display();
    void postorder();
    void preorder();
    void inorder();
    void rinorder(Node *);//recursive inorder
    
};
void createtree::rinorder(Node *t)
{
    if(t)
    {
        rinorder(t->lchild);
        cout<<t->data<<" ";
        rinorder(t->rchild);
    }
    
}
void createtree::inorder()
{
     struct Stack st;
    create(&st);
    long int num;
    Node *t=root;
    while(t || !isEmpty(st))
    {
        if(t!=NULL)
        {
            push(&st,(long int)t);//storing address in long int
            t=t->lchild;
        }
        else
        {
            num=pop(&st);
            t=(Node *)num;// long int to address
            cout<<t->data<<" ";
            t=t->rchild;
        }
    }
}
void createtree::preorder()
{
    struct Stack st;
    create(&st);
    long int num;
    Node *t=root;
    while(t || !isEmpty(st))
    {
        if(t!=NULL)
        {
            push(&st,(long int)t);
            cout<<t->data<<" ";
            t=t->lchild;
        }
        else
        {
            num=pop(&st);
            t=(Node *)num;
            t=t->rchild;
        }
    }
}
void createtree::postorder()
{
    struct Stack st;
    create(&st);
    long int num;
    Node *t=root;
    while(t || !isEmpty(st))
    {
        if(t!=NULL)
        {
            push(&st,(long int)t);
            t=t->lchild;
        }
        else
        {
            num=pop(&st);
            if(num>0)
            {
                push(&st,-1*num);
                t=((Node *)num)->rchild;
            }
            else{
                cout<<((Node *)(-1*num))->data<<" ";
                t=NULL;
            }
        }
    }
}
void createtree::display()
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
createtree::createtree()
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
int main()
{
    createtree r;
    r.inorder();
    return 0;

}
