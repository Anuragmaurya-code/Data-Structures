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
void insert(struct Array *arr,int x)
{   
    int i=arr->length-1;
    while(i>=0 && arr->A[i]>x)
    {   
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int main()
{
    struct Array arr={{1,2,3,4,6,8,10},10,7};
    insert(&arr,7);
    Display(arr);
    return 0;
}