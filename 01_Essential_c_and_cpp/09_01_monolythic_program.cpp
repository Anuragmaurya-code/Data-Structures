//monolytic style of programing
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int l,b;
    cout<<"Enter lenth and breath of rectangle ";
    cin>>l>>b;
    int area=l*b;
    int peri=2*(l+b);
    printf("%d is area\n%d is perimeter",area,peri);
    return 0;
}

