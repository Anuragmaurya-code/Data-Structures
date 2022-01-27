#include<iostream>
int main()
{
    char word[]="Anurag";
    //method 1
    char helper[10];
    int i,j;
    for(i=0;word[i]!='\0';i++)
    {}
    i--;
    for(j=0;i>=0;j++,i--)
    {
        helper[j]=word[i];
    }
    helper[j]='\0';
    for(i=0;helper[i]!='\0';i++)
    {
        word[i]=helper[i];
    }
    std::cout<<word<<std::endl;

    //Method 2
    char word2[]="Anurag";
    for(j=0;word2[j]!='\0';j++)
    {}
    j--;
    i=0;
    while(i<j)
    {
        char t;
        t=word2[i];
        word2[i]=word2[j];
        word2[j]=t;
        i++;
        j--;
    }
    std::cout<<word2;

    return 0;
}