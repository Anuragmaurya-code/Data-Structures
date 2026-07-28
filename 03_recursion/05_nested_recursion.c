#include <stdio.h>

int fun(int n)
{
    if(n>100)
        return n-10;
    else 
        return fun(fun(n+11));
}

int main()
{

    int i=fun(97);
    printf("%d", i);
    return 0;
}
