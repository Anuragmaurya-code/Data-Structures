//reference only for c++
#include<stdio.h>
int main()
{
    int a=10;
    int *ref=&a;//declaring and initializing reference variable
    printf("%d\n",a);
    printf("%d", *ref);
    return 0;
}
