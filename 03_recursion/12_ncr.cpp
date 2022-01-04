#include<iostream>
int fact(int n)
{
    if(n<=1)
        return 1;
    else 
        return fact(n-1)*n;
}
int ncr(int n,int r)//ncr combination using factorial function
{
    int num=fact(n);
    int den=fact(r)*fact(n-r);
    return num/den;
}

int pncr(int n,int r)//using pascal triangle
{
    if((n==1) || (n==r))
        return 1;
    return pncr(n-1,r-1)+pncr(n-1,r);
}
int main()
{
    std::cout<<ncr(3,2)<<std::endl;
    std::cout<<pncr(3,2);
    return 0;
}