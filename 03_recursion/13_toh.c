#include <stdio.h>

void TOH(int n,int A,int B,int C)
{
    if(n>0)
    {
    TOH(n-1,A,C,B);
    printf("Moving from %d to %d\n\n", A, C);
    TOH(n-1,B,A,C);
    }
}
void TOH1(int n,int A,int B,int C,int D)//for four towes
{
    if(n>0)
    {
    TOH1(n-1,A,B,D,C);
    printf("(%d,%d)\n", A, D);
    TOH1(n-1,C,A,B,D); 
    }
}

int main()
{
    TOH(3,1,2,3);
    TOH1(5,1,2,3,4);
    return 0;
}
