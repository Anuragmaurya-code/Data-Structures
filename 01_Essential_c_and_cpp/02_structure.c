#include<stdio.h>
struct reportcard
{
    char name[20];
    int roll;
    int tot_marks;

};

int main()
{
    int i;
    struct reportcard r[3];//declartion
    for(i=0;i<3;i++)//initialization
    {
        printf("Name ");
        scanf("%s", r[i].name);
        printf("roll no ");
        scanf("%d", &r[i].roll);
        printf("Total Marks ");
        scanf("%d", &r[i].tot_marks);
        printf("\n");
    }
    for(i=0;i<3;i++)
    {
        printf("%s %d %d\n", r[i].name, r[i].roll, r[i].tot_marks);
    }

    return 0;
}
