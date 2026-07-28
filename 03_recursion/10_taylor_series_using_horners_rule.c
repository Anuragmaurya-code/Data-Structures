#include <stdio.h>

float e1(float x,int n)//using loop
{
    float s=1;
    for(;n>0;n--)
    {
        s=1+x/n*s;
    }
    return s;
}

float e(float x,int n)//using recursion
{
    static float s=1;
    if(n==0)
        return s;
    s=1+x/n*s;
    return e(x,n-1);
}
int main()
{
    printf("%f\n", e(1,10));
    printf("%f", e(1,10));
    return  0;
}
