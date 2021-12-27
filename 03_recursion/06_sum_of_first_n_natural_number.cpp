#include<iostream>
using namespace std;
int nat_num(int n)
{
    if(n<=0)
        return 0;
    return n+nat_num(n-1);
    
}
int main()
{
    int sum=nat_num(5);
    cout<<sum;
}