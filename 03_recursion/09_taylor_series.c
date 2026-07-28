#include <stdio.h>

double tay(int x,int n)
{
    static float p=1,f=1;
    if(n==0)
        return 1;
    else 
    {
        double r=tay(x,n-1);
        p=p*x;
        f=f*n;
        return r+(p/f);
    }
           
}
int main()
{
    printf("%f\n", tay(1,10));
    return 0;
}
