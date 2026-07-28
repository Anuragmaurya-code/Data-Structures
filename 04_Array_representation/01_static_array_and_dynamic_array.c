#include <stdio.h>
#include <stdlib.h>
int main()
{
    int A[5]={1,2,3,4,5};//Static array in stack
    int *B=(int*)malloc(5 * sizeof(int));// dynamic array in heap 
    for(int i=0;i<5;i++)
        B[i]=i+6;
    for(int i=0;i<5;i++)
        printf("%d\n", A[i]);    
    for(int i=0;i<5;i++)
        printf("%d\n", B[i]);
    free(B);
    return 0;
}
