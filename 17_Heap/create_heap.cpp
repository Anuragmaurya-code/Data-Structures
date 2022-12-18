#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void create_heap(int A[],int n)
{
    int i,temp=A[n];
    i=n;
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

int delete_heap(int A[],int n)
{
    int i,temp,j;
    int val=A[1];
    A[1]=A[n];
    i=1;
    j=i*2;
    while(j<=n-1)
    {
        if(A[j+1]>A[j] && j+1<=n-1)//as it is possible that j=n i.e last element so it may cause 
            j=j+1;                 //error so j+1 need to be less than or equal to last element
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=i*2;
        }
        else break;
    }
    A[n]=val;
    return val;


}
int main()
{
    int A[]={0,10,20,30,25,5,40,35};
    create_heap(A,1);
    create_heap(A,2);
    create_heap(A,3);
    create_heap(A,4);
    create_heap(A,5);
    create_heap(A,6);
    create_heap(A,7);
    delete_heap(A,6);
    delete_heap(A,5);
    delete_heap(A,4);
    delete_heap(A,3);
    delete_heap(A,2);
    delete_heap(A,1);
    for(int num:A)
        cout<<num<<" ";
    return 0;
}


