#include <stdio.h>
int main()
{
    int a[5]={1,2,3,2,1};
    for(int i = 0; i < 5; i++)
    {
        int x = a[i];
        x=x*2;
        printf("%d\n", x);//Length of array as each int is of 4bit therefore 4*5=20bit lenth or size 
    }
    return 0;
}
