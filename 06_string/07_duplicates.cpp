#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char a4[10]="Hesllsos";//method 1 using for loop
    for(int i=0;a4[i]!='\0';i++)
    {
    if(a4[i]!=-1)
    {
    int count=1;
    for(int j=i+1;a4[j]!='\0';j++)
    {
        if(a4[i]==a4[j])
        {
            a4[j]=-1;
            count++;
        }
    }
    if(count>1)
    cout<<a4[i]<<" is duplicated "<<count-1<<" times"<<endl;
    }
    }
    cout<<"\n\n\n\n";



    //method 2 using hash table i.e hashing
    char word[]="helloehl";
    int a[26]={0},i;
    for(int i=0;word[i]!='\0';i++)
        a[word[i]-97]++;//writing program for lowercase word only

    for(int i=0;i<=25;i++)
    {
        if(a[i]>1)
        {
            char k=i+97;
            cout<<k<<" is repeated "<<a[i]-1<<" times"<<endl;
        }
    }





    return 0;}
