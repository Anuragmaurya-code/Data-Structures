#include <stdio.h>

void funct1(int n)
{
    if(n>0)
    {
        printf("%d", n);
        funct1(n-1);
    }
}
int main()
{
    int i=3;
    funct1(i);
    return 0;
}
