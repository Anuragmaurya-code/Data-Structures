#include<iostream>
#include<stdlib.h>
int main()
{
    int A[5]={1,2,3,4,5};//Static array in stack
    int *B=new int[5];// dynamic array in heap 
    for(int i=0;i<5;i++)
        B[i]=i+6;
    for(int i=0;i<5;i++)
        std::cout<<A[i]<<std::endl;    
    for(int i=0;i<5;i++)
        std::cout<<B[i]<<std::endl;
        delete [] B;
    
}