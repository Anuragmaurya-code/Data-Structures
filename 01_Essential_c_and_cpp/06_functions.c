#include <stdio.h>

void func(int x, int *y, int *z)
{
    x++;
    (*y)++;
    (*z)++;
}

int main()
{
    int a=5,b=10,c=15;

    printf("\nBefore calling function \na = %d\nb = %d\nc = %d\n", a, b, c);

    func(a, &b, &c);//here a is call by value ,b is call by address//c is call by refence

    printf("\nAfter calling function \na = %d\nb = %d\nc = %d\n", a, b, c);//here a is call by value ,b is call by address//c is call by refence    
    return 0;
}
