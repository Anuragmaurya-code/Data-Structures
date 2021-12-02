#include<iostream>
#include<stdio.h>
using namespace std;
void func(int x,int *y,int &z)
{
    x++;
    (*y)++;
    z++;
}
int main()
{
    int a=5,b=10,c=15;

    cout<<"\nBefore calling function "<<endl<<"a = "<<a<<"\nb = "<<b<<"\na = "<<c;

    func(a,&b,c);//here a is call by value ,b is call by address//c is call by refence

    cout<<endl<<"\nAfter calling function "<<endl<<"a = "<<a<<"\nb = "<<b<<"\na = "<<c;//here a is call by value ,b is call by address//c is call by refence    
    return 0;
}