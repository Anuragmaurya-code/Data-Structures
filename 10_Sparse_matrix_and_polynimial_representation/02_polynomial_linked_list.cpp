#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
struct Node{
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL;

void create()
{
    struct Node *t=NULL,*last=NULL;
    int num;
    cout<<"Enter the number of polynomials ";
    cin>>num;
    
    cout<<"Enter the coefficient and exponent of each polynomial ";
    for(int i=0;i<num;i++)
    {
        t=new Node;
        cin>>t->coeff>>t->exp;
        if(poly==NULL)
        {
            poly=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
        last->next=NULL;
    }
}

void display(struct Node *p)
{
    while(p)
    {
        cout<<p->coeff<<"x**"<<p->exp<<" + ";
        p=p->next;
    }
}

long eva(struct Node *p,int x)
{
    long val=0;
    while(p)
    {
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
}
int main()
{
    create();
    display(poly);
    cout<<"\nAnswer of Evaluation"<<eva(poly,1);
}