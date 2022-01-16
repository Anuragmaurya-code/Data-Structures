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
void RUA(struct Array arr)//reversing array using auxilary array B
{
    int arr2[(arr.length)];
    for(int i=(arr.length-1),j=0;i>=0;i--,j++)
    {
        arr2[j]=arr.A[i];
    }
    for(int i=0;i<(arr.length);i++)
    {
        arr.A[i]=arr2[i];
    }
    Display(arr);
}

void INT(struct Array *arr)//reversing array using interchanging
{
    for(int i=0,j=(arr->length-1);i<j;i++,j--)
        swap(&arr->A[i],&arr->A[j]);
}
void r_shift(struct Array *arr)//right shift 
{
    for(int j=(arr->length-1);j>0;j--)
        arr->A[j]=arr->A[j-1];
    arr->A[0]=0;
    
}

void r_shift_r(struct Array *arr)//right shift roatation
{
    for(int i=0;i<arr->length;i++)
    {
        int temp=arr->A[arr->length-1];
        for(int j=(arr->length-1);j>0;j--)
            arr->A[j]=arr->A[j-1];
        arr->A[0]=temp;
    }
}
void l_shift(struct Array *arr)//left shift 
{
    for(int j=1;j<(arr->length);j++)
        arr->A[j-1]=arr->A[j];
    arr->A[arr->length-1]=0;
    
}

void l_shift_r(struct Array *arr)//left shift roatation
{
    for(int i=1;i<=(arr->length);i++)
    {
        int temp=arr->A[0];
        for(int j=1;j<(arr->length);j++)
            arr->A[j-1]=arr->A[j];
        arr->A[(arr->length)-1]=temp;
    }
}
int main()
{
    struct Array arr={{1,2,3,4,5,6,8},10,7};
    r_shift_r(&arr);
    Display(arr);
    return 0;
}