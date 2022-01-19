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
    Array a1={{1,2,3,4,6,8,9,12,14,17},100,10};
    int max=a1.A[0],min=a1.A[0];

    for(int i=1;i<a1.length;i++)
    {
        if(a1.A[i]<min)
            min=a1.A[i];
        else if(a1.A[i]>max)
            max=a1.A[i];
    }
    cout<<max<<" "<<min;
    return 0;
}