#include <stdio.h>

int main()
{
    //Anagram using method 1 i.e for loop
    char word1[]="elbow";
    char word2[]="below";
    int i,j;
    for(i=0;word1[i]!='\0';i++)
    {
        for(j=0;word2[j]!='\0';j++)
        {
            if(word1[i]==word2[j])
                break;
        }
        if(word2[j]=='\0')
            break;
    }
    if(word1[i]=='\0')
        printf("Its an anagram \n");
    else
        printf("Its not an angram\n");

    //Anagram using method 2 using hasing

    char word3[]="cat";
    char word4[]="tac";

    int h[25]={0};
    for(i=0;word3[i]!='\0';i++)
        h[word3[i]-97]++;

    for(i=0;word4[i]!='\0';i++)
    {    if((h[word4[i]-97]-1)<0)
        {
            printf("Its not a anagram\n");
            break;
        }
    }
    if(word4[i]=='\0')
        printf("Its an anagram\n");

    //method 3 using betwise operator 

    char word5[]="tac";
    char word6[]="cat";
    int a=0;
    for(i=0;word5[i]!='\0';i++)//assigning word6 character as per bit
    {
        int b=1;//assigning 0 bit as 1 i.e turning is on
        b=b<<(word5[i]-97);//turning on the bit for that particular char
        if(a&b)
            continue;
        else
            a=a|b;
    }
    for(i=0;word6[i]!='\0';i++)
    {
        int b=1;//assigning 0 bit as 1 i.e turning is on
        b=b<<(word6[i]-97);//turning on the bit for that particular char
        if(a&b)
            continue;
        else
        {
            printf("Its not a anagram\n");
            break;
        }
    }
    if(word6[i]=='\0')
        printf("Its an anagram");
        
    return 0;
}
