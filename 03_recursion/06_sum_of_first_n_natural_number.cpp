#include<iostream>
using namespace std;
int sum(int n)
{
    if(n<=0)
        return 0;
    return n+sum(n-1);
    
}
int Isum(int n)
{
    int i;
    int sum=0;
    for (i=0;i<=n;i++)
    {
        sum=sum+i;
    }
    return sum;
}
int Isum(int n)
{
    int i,factorial=1;
    for(i=1;i<=n;i++)
        factorial=factorial*i;
    return factorial;

}
int main()
{
    int sum=Isum(5);
    cout<<sum;
}