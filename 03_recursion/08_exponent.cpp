#include<iostream>
using namespace std;
int expo(int m,int n)
{
    if(n<=0)
        return 1;
    return m*expo(m,n-1);
}
int expo1(int m,int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return expo1(m*m,n/2);
    else 
        return m*expo1(m*m,(n-1)/2);
}
int iexpo(int m,int n)
{
    int e=1,i;
    for(i=1;i<=n;i++)
    {
        e=e*m;
    }
    return e;
}

int main()
{
    int e=expo1(2,3);
    cout<<e;
    return 0;
}