#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Term
{
    int coeff;
    int expo;
};
struct polynomial
{
    int n;
    struct Term *t;
};
void create(struct polynomial * p)
{
    cout<<"Enter number of elements ";
    cin>>p->n;
    cout<<endl;
    p->t=new struct Term [p->n];
    for(int i=0;i<p->n;i++)
    {
        cout<<"Enter "<<i<<"th term coeff ";
        cin>>p->t[i].coeff;
        cout<<"Enter "<<i<<"th term expo ";
        cin>>p->t[i].expo;
        cout<<endl;
    }
}
void display(struct polynomial *p)
{
    for(int i=0;i<p->n;i++)
    {
        cout<<p->t[i].coeff<<"x"<<p->t[i].expo;
        if(i!=(p->n)-1)
            cout<<" + ";
    }
    cout<<endl;
}
struct polynomial addition(struct polynomial *p1,struct polynomial *p2)
{
    int i=0,j=0,k=0;
    struct polynomial sum;
    sum.t=new Term[p1->n + p2->n];
    while(i<p1->n && j<p2->n)
    {
        if(p1->t[i].expo>p2->t[j].expo)
            sum.t[k++]=p1->t[i++];
        else if(p2->t[j].expo>p1->t[i].expo)
            sum.t[k++]=p2->t[j++];
        else
        {
            sum.t[k].expo=p1->t[i].expo;
            sum.t[k++].coeff=p1->t[i++].coeff+p2->t[j++].coeff;
        }
    }
    for(;i<p1->n;i++)
        sum.t[k++]=p1->t[i];
    for(;j<p2->n;j++)
        sum.t[k++]=p2->t[j];
    sum.n=k;
    return sum;
}
int main()
{
    struct polynomial p1,p2,sum;
    create(&p1);
    display(&p1);
    create(&p2);
    display(&p2);
    sum=addition(&p1,&p2);
    display(&sum);
    return 0;
}