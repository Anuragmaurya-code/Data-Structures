#include<iostream>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[5]={1,3,5,7,9};
    int *p=&a[0],*p2,*p3;
    printf("Stack Memory array %d\n",p[2]);//using pointer p as array a
    p2=(int *)malloc(5*sizeof(int));//accessing heap memory using pointer in c
    p3=new int(5);//accessing heap memory using pointer in c++
    p2[0]=4;
    p3[0]=5;
    printf("Heap Memory array %d %d \n",p2[0],p3[0]);
    free(p2);//dealocating heap memory in c
    delete [ ] p3;//dealocating heap memory in c++ 
    printf("Heap Memory array %d %d ",p2[0],p3[0]);
    return 0;
}