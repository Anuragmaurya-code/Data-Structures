#include<stdio.h>
#include<stdlib.h>
struct Element{
    int i;
    int j;
    int x;
};
struct sparse
{
    int m;
    int n;
    int num;
    struct Element *elm;
};
void create(struct sparse *s)
{
    printf("Enter Dimension of sparse natrix ");
    scanf("%d%d",&s->m,&s->n);
    printf("\nEnter number of non-zero element ");
    scanf("%d",&s->num);
    s->elm=(struct Element *)malloc(s->num*sizeof(struct Element));
    for(int i=0;i<s->num;i++)
    {
        printf("\nEnter %d non-zero elememt ",i+1);
        scanf("%d%d%d",&s->elm[i].i,&s->elm[i].j,&s->elm[i].x);
    }
}
void display(struct sparse s)
{
    int k=0;
    for(int i=0;i<s.m;i++)
    {
        for(int j=0;j<s.n;j++)
        {
            if(i==s.elm[k].i && j==s.elm[k].j)
            printf("%d ",s.elm[k++].x);
            else
            printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct sparse s;
    create(&s);
    display(s);
    return 0;
}