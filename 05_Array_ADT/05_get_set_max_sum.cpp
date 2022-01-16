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
int Get(struct Array arr,int index)
{
    if(index>=0 && index<=arr.length )
        return arr.A[index];
    return -1;
}
void Set(struct Array *arr,int index,int value)
{
    if(index>=0 && index<=arr->length )
        arr->A[index]=value;
}
int Max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}
int Min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}
int Sum(struct Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
    {
        sum=sum+arr.A[i];
    }
    return sum;
}
float Avg(struct Array arr)//u can call function sum in avg and type cast it as float-> (float)Sum(arr)/arr.length
{
    float sum=0;
    for(int i=0;i<arr.length;i++)
    {
        sum=sum+arr.A[i];
    }
    return sum/arr.length;
}
int RSum(struct Array arr,int n)//by recursion
{
    if(n>=0)
        return RSum(arr,n-1)+arr.A[n];
    return 0;
}
int main()
{
    struct Array arr={{1,2,3,4,5,6,8},10,7};
    cout<<Avg(arr);
    return 0;
}