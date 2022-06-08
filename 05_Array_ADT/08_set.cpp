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
bool sort(struct Array arr)
{
    int i=0;
    while(i<arr.length-1)
    {
        if(arr.A[i]>arr.A[i+1])
            return false;
        i++;

    }
    return true;
}
struct Array Union(struct Array arr1,struct Array arr2)
{
    struct Array arr3;
    if(sort(arr1) && sort(arr2))//if arr1 and arr2 are sorted
    {
        int i=0,j=0,k=0;
        while(i<arr1.length &&  j<arr2.length)
        {
            if(arr1.A[i]<arr2.A[j])
                arr3.A[k++]=arr1.A[i++];
            else if(arr1.A[i]==arr2.A[j])
            {
                arr3.A[k++]=arr1.A[i++];
                j++;
            }
            else
                arr3.A[k++]=arr2.A[j++];
        }
        for(;i<arr1.length;i++)
            arr3.A[k++]=arr1.A[i];
        for(;j<arr2.length;j++)
            arr3.A[k++]=arr2.A[j];
        arr3.length=k;
        arr3.size=100;
        return arr3;
    }
    else
    {
        int i=0,j=0,k=0,m=0;
        for(i=0;i<arr1.length;i++,k++)
            arr3.A[k]=arr1.A[i];
        for(i=0;i<arr2.length;i++)
        {
            int l=0,j=0;
            while(j<arr1.length)
            {
                if(arr2.A[i]==arr3.A[j])//checking for every element of array 1 if it exist in array 2
                {
                    l=1;
                    break;
                }
                j++;

            }
            if(l==0)
                arr3.A[k++]=arr2.A[i];
        }
        arr3.length=k;
        arr3.size=100;
        return arr3;
    }
}

struct Array Intersection(struct Array arr1,struct Array arr2)
{
    struct Array arr3;
    if(sort(arr1) && sort(arr2))//if arr1 and arr2 are sorted
    {
        int i=0,j=0,k=0;
        while(i<arr1.length &&  j<arr2.length)
        {
            if(arr1.A[i]<arr2.A[j])
                i++;
            else if(arr1.A[i]==arr2.A[j])
            {
                arr3.A[k++]=arr1.A[i];
                i++;
                j++;
            }
            else
                j++;
        }
        arr3.length=k;
        arr3.size=100;
        return arr3;
    }
    else
    {
        int i=0,j=0,k=0;
        for(i=0;i<arr1.length;i++)
        {
            for(j=0;j<arr2.length;j++)
            {
                if(arr1.A[i]==arr2.A[j])
                    {
                        arr3.A[k++]=arr1.A[i];
                        break;
                    }
            }
        }
        arr3.length=k;
        arr3.size=100;
        return arr3;
    }
}

struct Array Difference(struct Array arr1,struct Array arr2)
{
    struct Array arr3;
    if(sort(arr1) && sort(arr2))//if arr1 and arr2 are sorted
    {
        int i=0,j=0,k=0;
        while(i<arr1.length &&  j<arr2.length)
        {
            if(arr1.A[i]<arr2.A[j])
                arr3.A[k++]=arr1.A[i++];

            else if(arr2.A[j]<arr1.A[i])
                j++;
                
            else if(arr1.A[i]==arr2.A[j])
            {
                i++;
                j++;
            }
        }
        for(;i<arr1.length;i++)
            arr3.A[k++]=arr1.A[i];
        arr3.length=k;
        arr3.size=100;
        return arr3;
    }
    else
    {
        int i=0,j=0,k=0,m=0;
        for(i=0;i<arr1.length;i++)
        {
            m=0;
            for(j=0;j<arr2.length;j++)
            {
                if(arr1.A[i]==arr2.A[j])
                    {
                        m=1;
                        break;
                    }
            }
            if(m==0)
                arr3.A[k++]=arr1.A[i];
        }
        arr3.length=k;
        arr3.size=100;
        return arr3;
    }
}

int main()
{
    struct Array arr1={{2,6,10,15,12,25},100,6};
    struct Array arr2={{3,6,7,15,20},100,5};
    struct Array d=Difference(arr1,arr2);
    Display(d);
    return 0;
}
