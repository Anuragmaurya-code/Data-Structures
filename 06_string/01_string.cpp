#include<iostream>
#include<stdio.h>
int main()
{
    char name1[]="Anurag Maurya";
    char name2[20];
    std::cout<<"Enter your name ";
    gets(name2);
    printf("ok %s\n",name2);
    std::cout<<name1<<" and "<<name2<<" are friends";


}