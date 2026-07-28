#include <stdio.h>

int main()
{
    char sample_word[11]={'T','a','j',' ',' ','m','a','h','a','l','\0'};
    int v_count=0,c_count=0;
    for(int i=0;sample_word[i]!='\0';i++)
    {
        if(sample_word[i]=='a'||sample_word[i]=='e'|| sample_word[i]=='i'|| sample_word[i]=='o' || sample_word[i]=='u' || 
        sample_word[i]=='A'|| sample_word[i]=='E' || sample_word[i]=='I'|| sample_word[i]=='O' || sample_word[i]=='U')
        v_count++;//counting as vowel
        
        else if((sample_word[i]>=65 && sample_word[i]<=90) || (sample_word[i]>=97 && sample_word[i]<122))
            c_count++;//counting consonent
    }
    printf("number of vowels = %d\nnumber of consonent = %d\n", v_count, c_count);

    //count words
    int space=0;
    for(int i=0;sample_word[i]!='\0';i++)
    {
        if(sample_word[i]==' '&& sample_word[i-1]!=' ')//checking if its a space and not white space
            space++;//counting space
    }
    printf("number of words = %d", space+1);
    
    return 0;
}
