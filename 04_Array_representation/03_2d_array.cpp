#include<iostream>
#include<stdlib.h>
int main()
{
    int A[2][2];//Method 1:Whole 2D array in stack
    A[0][0]=2;
    A[0][1]=3;
    A[1][0]=4;
    A[1][1]=5;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            std::cout<<A[i][j]<<" ";
        std::cout<<"\n";
    }    
    std::cout<<"\n";

    int *B[2];//Method 2:Row in stack and column in heap
    B[0]=new int[2];//Return int pointer
    B[1]=new int[2];//Return int pointer
    B[0][0]=12;
    B[0][1]=13;
    B[1][0]=14;
    B[1][1]=15;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            std::cout<<B[i][j]<<" ";
        std::cout<<"\n";
    }    
    std::cout<<"\n";

    int **C;//Method 3: complete 2D array in heap
    C=new int*[2];//Return int double pointer
    C[0]=new int[2];//Return int pointer
    C[1]=new int[2];//Return int pointer
    C[0][0]=112;
    C[0][1]=113;
    C[1][0]=114;
    C[1][1]=115;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            std::cout<<C[i][j]<<" ";
        std::cout<<"\n";
    }    
    std::cout<<"\n";

    
    return 0;
}