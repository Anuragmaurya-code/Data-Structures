#include<iostream>
#include<stdlib.h>
using namespace std;
void funct1(int *a)
{
    int i;
    for(i=0;i<5;i++)
    {
        cout<<endl<<"funt1 "<<a[i];
    }
}  
void funct2(int a[])
{
    int i;
    for(i=0;i<5;i++)
    {
        cout<<endl<<"funt2 "<<a[i];
    }
}  
int * funct3(int size)//returning address of an  array , created and stored in heap by function
{
    int *a,i;
    a=new int[size];//or  a=(int *)malloc(size of array*size of data type) // creating an array in heap memory
    for(i=0;i<size;i++)
    {
        a[i]=i+1;
    }
    return a;//returning a pointer which hold an array stored in heapmemory
}
int main()
{

    int a[]={0,1,2,3,4};
    funct1(&a[0]);//pasing array as parameter to funct function
    funct2(a);//another way to pass funct as parameter

    //returning an array from function
    int sz=6,*ptr,i;
    ptr=funct3(sz);
    for(i=0;i<sz;i++)
    {
        cout<<endl<<"funct3 "<<ptr[i];
    }
}

