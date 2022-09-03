#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

struct Node {
    Node* lchild;
    int data;
    int height;
    Node* rchild;
}*root=NULL;

int NodeHeight(struct Node *p)
{
    if(p==NULL)
        return 0;
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(struct Node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return  hl-hr;
}

struct Node * LLRotation(struct Node *p)
{
    Node *pl=p->lchild;
    Node *plr=pl->rchild;

    p->lchild=plr;
    pl->rchild=p;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(p==root)
    {   root=pl;
        return pl;
    }
    return p;

}





struct Node * RRRotation(struct Node *p)
{
    Node *pr=p->rchild;
    Node *prl=pr->lchild;

    p->rchild=prl;
    pr->lchild=p;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    if(p==root)
    {  
       root=pr;
        return pr;
    }

    return p;

}

struct Node * LRRotation(struct Node *p)
{
    Node *pl=p->lchild;
    Node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);

    if(p==root)
        root=plr;

    return plr;

}

struct Node * RLRotation(struct Node *p)
{
    Node *pr=p->rchild;
    Node *prl=pr->lchild;

    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
    prl->lchild=p;
    prl->rchild=pr;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

    if(p==root)
        root=prl;

    return prl;

}


struct Node* Rinsert(struct Node *p,int key)
{
    struct Node *t;
    if(p==NULL)
    {
        t=new Node ;
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(p->data>key)
        p->lchild=Rinsert(p->lchild,key);
    else if(p->data<key)
        p->rchild=Rinsert(p->rchild,key);
    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    return p;
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
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(p->data<key)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(NodeHeight(p->lchild)>NodeHeight(p->rchild))
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
     // Update height
    p->height = NodeHeight(p);
 
    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }
 
    return p;
}

void Display(struct Node *p)
{
    cout<<p->data<<endl;
    if(p->lchild)
    {
        cout<<"left child of "<<p->data<<" is ";
        Display(p->lchild);
    }
        
    if(p->rchild)
    {
        cout<<"right child of "<<p->data<<" is ";
        Display(p->rchild);
    }
}


int main()
{
    root=Rinsert(root,50);
    Rinsert(root,60);
    Rinsert(root,40);
    Rinsert(root,30);
    Rinsert(root,55);
    Rinsert(root,45);
    Rinsert(root,35);

    Delete(root,60);
    Display(root);
    return 0;
}