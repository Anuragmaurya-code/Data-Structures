#include<iostream>
#include<stdio.h>
using namespace std;
void perm(char s[],int k)
{
    static int A[10]={0};
    static char Res[10];
    int i;
    if(s[k]=='\0')
    {
        Res[k]='\0';
        cout<<Res<<endl;
    }
    else
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                Res[k]=s[i];
                A[i]=1;
                perm(s,k+1);
                A[i]=0;
            }
        }
    }
}
int main()
{
    char s[]="ABC";
    perm(s,0);
    return 0;}