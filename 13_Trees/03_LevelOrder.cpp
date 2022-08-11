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
    
};
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
    t.Levelorder();
    return 0;
}