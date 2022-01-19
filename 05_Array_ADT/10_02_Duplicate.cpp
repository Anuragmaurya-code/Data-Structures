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
    // Array a1={{1,2,3,3,4,4,4,5},100,8};//Method 1 for sorted
    // int dup=0;
    // for(int i=0;i<a1.length-1;i++)
    // {
    //     if(a1.A[i]==a1.A[i+1] && a1.A[i]!=dup)
    //     {   
    //         cout<<a1.A[i]<<" is duplicated"<<endl;
    //         dup=a1.A[i];
    //     }

    // }

    // Array a2={{1,1,2,3,4,5,5,5},100,8};//Method 2 for sorted
    // int j;
    // for(int i=0;i<a1.length-1;i++)
    // {
    //     if(a2.A[i]==a2.A[i+1])
    //     {   
    //         j=i+1;
    //         cout<<a2.A[i]<<" is duplicated"<<endl;
    //         while(a2.A[i]==a2.A[j]) j++;
    //         i=j-1;
    //     }
    // }

    // Array a3={{1,1,2,3,4,5,5,5},100,8};//Method 3 using hashing
    // //here l=1,h=5
    // int A1[6]={0};
    // for(int i=0;i<a3.length;i++)
    // {
    //     A1[a3.A[i]]++;
    // }

    // for(int i=1;i<6;i++)
    // {
    //     if(A1[i]>1)
    //         cout<<i<<" is duplicated "<<A1[i]-1<<" times"<<endl;
    // }

    // Array a4={{5,7,5,4,3,2,5,3,2},100,9};//Method 4 for unsorted
    // for(int i=0;i<a4.length-1;i++)
    // {
    //     if(a4.A[i]!=-1)
    //     {
    //         int count=1;
    //         for(int j=i+1;j<a4.length;j++)
    //         {
    //             if(a4.A[i]==a4.A[j])
    //             {a4.A[j]=-1;
    //             count++;}
    //         }
    //         if(count>1)
    //             cout<<a4.A[i]<<" is duplicated "<<count<<" times"<<endl;

    //     }
    // }

    Array a5={{5,4,8,4,6,7,5,4},100,8};//Method 5 for unsorted using hashing

    //here l is 4 and h is 8
    int h=8;
    int A1[h+1]={0};

    for(int i=0;i<a5.length;i++)
    {
        A1[a5.A[i]]++;
    }
    for(int i=1;i<=h;i++)
    {
        if(A1[i]>1)
            cout<<i<<" is repeated "<<A1[i]<<" times"<<endl;
    }




}