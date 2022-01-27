#include<iostream>
using namespace std;
int main()
{
    char word[]="Hellohedppd";
    int a=0;//assigning all bits as zero
    for(int i=0;word[i]!='\0';i++)
    {
        int b=1;//assigning 0 bit as 1 i.e turning is on
        b=b<<word[i]-97;//turning on the bit for that particular char
        if(a&b)
            cout<<"Dublicated letter "<<word[i]<<endl;
        else
            a=a|b;
    }
    return 0;
}