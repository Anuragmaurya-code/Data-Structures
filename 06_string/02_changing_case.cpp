#include<iostream>
int main()
{
    char name[]="AnuRAG maURyA";
    for(int i=0;name[i]!='\0';i++)
    {
        if(name[i]>=65 &&name[i]<=90)//if chararcter is uppercase
            name[i]=name[i]+32;
        else if(name[i]>=97 && name[i]<=122)//if chararcter is lowercase
            name[i]=name[i]-32;
    }
    std::cout<<name;
    

    return 0;
}