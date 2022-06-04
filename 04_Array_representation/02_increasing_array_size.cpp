#include<iostream>
int main()
{
    int *p=new int[5];
    for(int i=0;i<5;i++)
        p[i]=i;
    int *q=new int [10];
    for(int i=0;i<5;i++)
        q[i]=p[i];
    q[6]=456;
    p=q;//changing size of array
    q=NULL;
    for(int i=0;i<10;i++)
        std::cout<<p[i]<<std::endl;
    return 0;
}