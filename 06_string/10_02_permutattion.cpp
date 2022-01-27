#include<iostream>
using namespace std;
void swap(char *c1,char *c2)
{
    char t=*c1;
    *c1=*c2;
    *c2=t;
}
void perm(char s[],int l,int h)
{
    if(l==h)
    {
        cout<<s<<endl;
    }
    else
    {
        for(int i=l;i<=h;i++)
        {
            swap(&s[i],&s[l]);
            perm(s,l+1,h);
            swap(&s[i],&s[l]);
        }
    }
}
int main()
{
    char s[]="ABC";
    perm(s,0,2);
}