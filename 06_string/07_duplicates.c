#include <stdio.h>

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
                printf("%c is duplicated %d times\n", a4[i], count-1);
        }
    }
    printf("\n\n\n\n");

    //method 2 using hash table i.e hashing
    char word[]="helloehl";
    int a[26]={0};
    for(int i=0;word[i]!='\0';i++)
        a[word[i]-97]++;//writing program for lowercase word only

    for(int i=0;i<=25;i++)
    {
        if(a[i]>1)
        {
            char k=i+97;
            printf("%c is repeated %d times\n", k, a[i]-1);
        }
    }

    return 0;
}
