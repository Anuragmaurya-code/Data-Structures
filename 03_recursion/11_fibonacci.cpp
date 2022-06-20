#include<iostream>
using namespace std;
int ifib1(int n)//fibonacci series using loops/iteration
{

    int t0=0;
    int t1=1,s;
    for(int i=2;i<=n;i++)
    {
        s=t1+t0;
        t0=t1;
        t1=s;
    }
    return s;
}
int ifib2(int n)//fibonacci series using loops/iteration
{

    int f[n];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
       f[i]=f[i-2]+f[i-1];
    }
    return f[n];
}
int rfib(int n)//fibonacci series using recursion
{
    if(n<=1)
        return n;
    return rfib(n-1)+rfib(n-2);
}
int F[10];
int mfib(int n)//fibonacci series using recursion using memoization
{
    if(n<=1)
        return n;
    else
    {
        if(F[n-1]==-1)//it means no value entered till yet as it is -1
            F[n-1]=mfib(n-1);
        if(F[n-2]==-1)
            F[n-2]=mfib(n-2);
        F[n]=F[n-1]+F[n-2];
        return F[n-1]+F[n-2];
    }
}

int main()
{
    for(int i=0;i<=10;i++)
        F[i]=-1;
    cout<<ifib1(7)<<endl;
    cout<<ifib2(7)<<endl;
    cout<<rfib(7)<<endl;
    cout<<mfib(5);
    return 0;
}