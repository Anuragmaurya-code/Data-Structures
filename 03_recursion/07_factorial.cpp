#include<iostream>
using namespace std;
int fac(int n)
{
    if(n<=0)
        return 1;
    else 
       return n*fac(n-1);
}
int main()
{
    int factorial=fac(5);
    cout<<factorial;
    return 0;
}