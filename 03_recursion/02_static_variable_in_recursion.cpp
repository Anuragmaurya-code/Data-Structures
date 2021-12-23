#include<iostream>
using namespace std;
int static_fun(int n)
{
    static int x=0;
    if(n>0)
    {
        x++;
        return static_fun(n-1)+x;
    }
    return 0;
}
int main()
{
    int a,b=5;
    a=static_fun(b);
    cout<<a;
    return 0;
}