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
int LinearSearch(struct Array *arr,int value)
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==value)
        {
            swap(&arr->A[i-1],&arr->A[i]);
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Array arr={{1,2,3,4,5,6,7},10,7};
    cout<<LinearSearch(&arr,4)<<endl;
    Display(arr);
    return 0;
}
