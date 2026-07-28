#include <stdio.h>

int main()
{
    char name1[]="Anurag Maurya";
    char name2[20];
    printf("Enter your name ");
    gets(name2);
    printf("ok %s\n",name2);
    printf("%s and %s are friends", name1, name2);

    return 0;
}
