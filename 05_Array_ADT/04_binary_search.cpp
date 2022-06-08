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
int BinarySearch(struct Array arr,int value)
{
    if(arr.length>0)
    {
        int l=0;
        int h=arr.length-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(value==arr.A[mid])
                return mid;
            else if(arr.A[mid]<value)
                l=mid+1;
            else
                h=mid-1;
        }
    }
    return -1;
}
int RBinarySearch(struct Array arr,int value,int l,int h)
{
    if(l<=h)
    {
        int mid=(l+h)/2;
        if(value==arr.A[mid])
            return mid;  
        else if(value<ar r.A[mid])
            return RBinarySearch(arr,value,l,mid-1);
        else 
            return RBinarySearch(arr,value,mid+1,h);
        } 
    return -1;
}

int main()
{
    struct Array arr={{1,2,3,4,5,6,7},10,7};
    cout<<RBinarySearch(arr,6,0,arr.length-1)<<endl;
    Display(arr);
    return 0;
}
