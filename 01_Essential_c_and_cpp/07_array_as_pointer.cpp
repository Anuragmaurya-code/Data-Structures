#include<iostream>
using namespace std;
void funct1(int *a)
{
    a[0]=4;
    a[1]=3;
    a[2]=2;
    a[3]=1;
    a[4]=0;
}  
void funct2(int a[])
{
    a[0]=00;
    a[1]=10;
    a[2]=20;
    a[3]=30;
    a[4]=40;
}  
int main()
{

    int a[]={0,1,2,3,4},i;
    funct1(&a[0]);//pasing array as parameter to funct function
    funct2(a);//another way to pass funct as p
    for(i=0;i<5;i++)
    {
        cout<<a[i]<<endl;
    }

}

