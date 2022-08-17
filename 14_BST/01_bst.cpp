#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

struct Node {
    Node* lchild;
    int data;
    Node* rchild;
}*root=NULL;

struct Node* Rinsert(struct Node *p,int key)
{
    struct Node *t;
    if(p==NULL)
    {
        t=new Node ;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(p->data>key)
        p->lchild=Rinsert(p->lchild,key);
    else if(p->data<key)
        p->rchild=Rinsert(p->rchild,key);
    return p;
}
void insert(int key)
{
    Node *p=root,*r;
    if(p==NULL)
    {
        p=new Node;
        p->lchild=p->rchild=NULL;
        p->data=key;
        root=p;
        return;
    }
    else{
        while(p!=NULL)
        {
            r=p;
            if(p->data<key)
                p=p->rchild;
            else if(p->data>key)
                p=p->lchild;
            else 
                return;
        }
        p=new Node;
        p->lchild=p->rchild=NULL;
        p->data=key;
        if(r->data<key)
            r->rchild=p;
        else
            r->lchild=p;
    }
}

void inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" "<<flush;
        inorder(p->rchild);
    }
}

int Height(struct Node *t)
{
    if(t==NULL)
        return 0;
    int lh=Height(t->lchild);
    int rh=Height(t->rchild);
    return lh<rh?rh+1:lh+1;
}
struct Node *Inprec(Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}

struct Node *Insucc(Node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}

struct Node *Delete(Node *p,int key)
{
    struct Node *t=NULL;
    if (p==NULL)
        return nullptr;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
    if(p->data>key)
        p->lchild=Delete(p->lchild,key);
    else if(p->data<key)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            t=Inprec(p->lchild);
            p->data=t->data;
            p->lchild=Delete(p->lchild,t->data);
        }
        else
        {
            t=Insucc(p->rchild);
            p->data=t->data;
            p->rchild=Delete(p->rchild,t->data);
        }
    }
    return p;
}

void CreatePre()
{
    int pre[]={30,20,10,15,25,40,50,45};
    int n=8;
    stack<Node *> st;
    Node *p,*t;
    root=new Node;
    int i=0;
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    while (i<n)
    {
       if(p->data>pre[i])
       {
        t=new Node;
        t->data=pre[i++];
        t->lchild=t->rchild=NULL;
        p->lchild=t;
        st.emplace(p);
        p=t;
       }
       else if(p->data<pre[i] && st.empty()?1:(st.top()->data>pre[i]?1:0))
       {
        t=new Node;
        t->data=pre[i++];
        t->lchild=t->rchild=NULL;
        p->rchild=t;
        p=t;
       }
       else
        {
            p=st.top();
            st.pop();
        }
    }
    
}
int main()
{
    int A[]={30,20,10,15,25,40,50,45};
    CreatePre();
    inorder(root);
    return 0;
}