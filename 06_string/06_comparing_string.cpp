#include<iostream>
int main()
{
    //comparing two strings
    char A[]="Painter";
    char B[]="painter";
    int i,j;
    for(i=0,j=0;A[i]!='\0',B[j]!='\0';j++,i++)//checking condition if string ends
    {
        if(A[i]>=65 && A[i]<=90)//checking if its uppercase then converting to lower case 
            A[i]=A[i]+32;
        else if(B[i]>=65 && B[i]<=90)//checking if its uppercase then converting to lower case 
            B[i]=B[i]+32;
        if(A[i]!=B[j])//checking if they are not equal
            break;
    }
    if(A[i]==B[j])
        std::cout<<"both are equal"<<std::endl;
    else if(A[i]>B[j])
        std::cout<<"A is greater"<<std::endl;
    else
        std::cout<<"B is greater"<<std::endl;


    //checking if Palindrone

    char word[]="madami";
    //method 1
    char helper[10];//helper string/array
    for(i=0;word[i]!='\0';i++)//incrementing i value till it reacher the last index
    {}
    i--;
    for(j=0;i>=0;j++,i--)//copying reverse of word in helper
    {
        helper[j]=word[i];
    }
    helper[j]='\0';//assigining last value with null term
    for(i=0;helper[i]!='\0';i++)
    {
        if(word[i]!=helper[i])//if not equal break out of loop
            break;
    }
    if(word[i]=='\0')//checking if it reached last till last null term
        std::cout<<"String is pallindrone"<<std::endl;
    else
        std::cout<<"string is not palindrone"<<std::endl;

    //Method 2
    char word2[]="MADoM";
    for(j=0;word2[j]!='\0';j++)
    {}
    j--;
    i=0;
    while(i<j)
    {
        if(word2[i]!=word2[j])//if not equal break out of loop
            break;
        i++;
        j--;
    }
    if(word2[i]==word2[j])//checking if they are equal
        std::cout<<"String is pallindrone"<<std::endl;
    else
        std::cout<<"string is not palindrone"<<std::endl;
}