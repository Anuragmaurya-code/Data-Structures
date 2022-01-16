#include<iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        std::cout<<arr.A[i]<<" ";
    }
}
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
void neg(struct Array *arr)
{   
    int i=0,j=arr->length-1;
    while(i<j)
    {   
        while (arr->A[i]<0)i++;
        while(arr->A[j]>0)j--;
        if(i<j) swap(&arr->A[i],&arr->A[j]);       
    }
}

int main()
{
    struct Array arr={{-1,2,-3,4,-5,8,-10},10,7};
    neg(&arr);
    Display(arr);
    return 0;
}