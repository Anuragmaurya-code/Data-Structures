#include<iostream>
using namespace std;
int fac(int n)
{
    if(n<=0)
        return 1;
    else 
       return n*fac(n-1);
}
int Ifac(int n)
{
    int i,factorial=1;
    for(i=1;i<=n;i++)
        factorial=factorial*i;
    return factorial;

}

int main()
{
    int factorial=Ifac(5);
    cout<<factorial;
    return 0;
}