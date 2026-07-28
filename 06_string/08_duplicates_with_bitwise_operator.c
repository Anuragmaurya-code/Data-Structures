#include <stdio.h>

int main()
{
    char word[]="Hellohedppd";
    int a=0;//assigning all bits as zero
    for(int i=0;word[i]!='\0';i++)
    {
        int b=1;//assigning 0 bit as 1 i.e turning is on
        b=b<<(word[i]-97);//turning on the bit for that particular char
        if(a&b)
            printf("Dublicated letter %c\n", word[i]);
        else
            a=a|b;
    }
    return 0;
}
