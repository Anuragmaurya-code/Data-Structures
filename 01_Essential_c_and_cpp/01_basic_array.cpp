#include <iostream>
using namespace std;
int main()
{
    int a[5]={1,2,3,2,1};
    for(int x:a)
    {
        x=x*2;
        cout<<x<<endl;//Length of array as each int is of 4bit therefore 4*5=20bit lenth or size 
    }
     
}