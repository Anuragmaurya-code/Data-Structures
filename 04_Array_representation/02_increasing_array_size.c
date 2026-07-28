#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p=(int*)malloc(5 * sizeof(int));
    for(int i=0;i<5;i++)
        p[i]=i;
    int *q=(int*)malloc(10 * sizeof(int));
    for(int i=0;i<5;i++)
        q[i]=p[i];
    q[6]=456;
    p=q;//changing size of array
    q=NULL;
    for(int i=0;i<10;i++)
        printf("%d\n", p[i]);
    return 0;
}
