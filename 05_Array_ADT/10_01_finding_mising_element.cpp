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
int main()
{
    Array arr={{1,2,3,4,5,7,8},100,7};
    int sum=0,s=0;
    for(int i=0;i<arr.length;i++)//method 1
        sum=sum+arr.A[i];
    
    s=arr.A[arr.length-1]*(arr.A[arr.length-1]-1)/2;

    Array arr2={{6,7,10,11,13,14,15},100,7};//Menthod 2 for multiple missing element
    int diff=arr2.A[0]-0;
    for(int i=0;i<arr2.length;i++)
    {
        if(arr2.A[i]-i!=diff)
        {
            while(diff<(arr2.A[i]-i))
            {
                cout<<diff+i<<endl;
                diff++;
            }
        }
    }

    Array arr3={{1,7,5,2,3},100,5};//Menthod 3 for multiple missing element using hashing
    //here l=1 h=7
    int A1[8]={0};
    for(int i=0;i<arr3.length;i++)
        A1[arr3.A[i]]++;
    for(int i=1;i<8;i++)
    {
        if(A1[i]==0)
            cout<<"element "<<i<< " is missing"<<endl;
    }
    return 0;
    }