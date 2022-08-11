#include<iostream>
#include<stdlib.h>
using namespace std;
#include<queue>
#include "Node.h"

class createtree
{
    public:
    Node *p,*t;
    int x;
    queue<Node*> q;
    createtree();
    void Levelorder();
    int count(Node *p);
    int count(){ count(root); }
    int height(Node *p);
    int height(){height(root);}
    int leafNodeCount(Node *p);
    int leafNodeCount(){ leafNodeCount(root); }
};
int createtree::leafNodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = leafNodeCount(p->lchild);
        y = leafNodeCount(p->rchild);
        if (p->lchild == nullptr && p->rchild == nullptr){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
int createtree::count(Node *p)
{
    if(p!=NULL)
        return count(p->lchild)+count(p->rchild)+1;
    
    return 0;
}
int createtree::height(Node *p)
{
    int x,y;
    if(p)
    {
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}
void createtree::Levelorder()
{
    queue<Node*> q;
    Node *t=root;
    q.emplace(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        std::cout<<t->data<<" ";
        if(t->lchild)
        {
            q.emplace(t->lchild);
        }
        if(t->rchild)
        {
            q.emplace(t->rchild);
        }
        
    }

    
}
createtree::createtree()
{   
        cout<<"Enter the root Node data  ";
        cin>>root->data;
        root->lchild=root->rchild=NULL;
        q.emplace(root);
        while(!q.empty())
        {
            p=q.front();
            q.pop();
            cout<<"Enter the value of left child of "<<p->data<<" ";
            cin>>x;
            if(x!=-1)
            {
                t=new Node;
                t->data=x;
                t->lchild=t->rchild=nullptr;
                p->lchild=t;
                q.emplace(t);
            }
            cout<<"Enter the value of right child of  "<<p->data<<" ";
            cin>>x;
            if(x!=-1)
            {
                t=new Node;
                t->data=x;
                t->lchild=t->rchild=nullptr;
                p->rchild=t;
                q.emplace(t);
            }

        }
    }

int main()
{
    createtree t;
    cout<<"\nleaf Node "<<t.leafNodeCount();
    return 0;
}