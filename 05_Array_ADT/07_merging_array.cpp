#include<iostream>
using namespace std;
struct Array
{
    int A[100];
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
void Merge(struct Array arr1,struct Array arr2,struct Array *arr3)
{
    int i=0,j=0,k=0;
    while(i<arr1.length && j<arr2.length)
    {
        if(arr1.A[i]<arr2.A[j])
            arr3->A[k++]=arr1.A[i++];
        else
            arr3->A[k++]=arr2.A[j++];
    }
    for(;i<arr1.length;i++)
        arr3->A[k++]=arr1.A[i++];
    for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j++];   
}

int main()
{
    struct Array arr1={{1,4,7,13,17,20,36},100,7};
    struct Array arr2={{6,8,9,10,11,24},100,6};
    struct Array arr3={{},arr1.size+arr2.size,arr1.length+arr2.length};    
    Merge(arr1,arr2,&arr3);
    std::cout<<sizeof(arr3)<<endl;
    Display(arr3);
    return 0;
}