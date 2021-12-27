#include<iostream>
using namespace std;
void fun2(int);
void fun1(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        fun2(n-1);
    }
    
}
void fun2(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        fun1(n/2);
    }
}
int main()
{
    fun1(10);
    return 0;
}