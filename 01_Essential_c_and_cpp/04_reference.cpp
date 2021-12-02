//reference only for c++
#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int &ref=a;//declaring and initializing reference variable
    printf("%d\n",a);
    cout<<ref;
    return 0;
}