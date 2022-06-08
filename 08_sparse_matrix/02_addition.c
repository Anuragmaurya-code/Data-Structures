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
    printf("Enter Dimension of sparse matrix ");
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
struct sparse *add(struct sparse *s1,struct sparse *s2)
{
    int i=0,j=0,k=0;//i for referrring elements of array of struct Element pointed by elm  in sparse structure pointed by s1
                    // j for s2 and k for sum
    if(s1->m!=s2->m || s1->n!=s2->n)
        return 0;
    struct sparse *sum=(struct sparse *)malloc(sizeof(struct sparse));
    sum->m=s1->m;
    sum->n=s1->n;
    sum->elm=(struct Element *)malloc(sizeof(struct Element)*s1->num+s2->num);
    while (i<s1->num && j<s2->num)
    {
        if(s1->elm[i].i<s2->elm[j].i)// row of s1 is less than s2
            sum->elm[k++]=s1->elm[i++];

        else if(s1->elm[i].i>s2->elm[j].i)//row of s2 is less than s1
            sum->elm[k++]=s2->elm[j++];

        else
            if(s1->elm[i].j<s2->elm[j].j)//row of s1 and s2 is same but column of s1 is less than s2
                sum->elm[k++]=s1->elm[i++];

            else if(s1->elm[i].j>s2->elm[j].j)//row of s1 and s2 is same but column of s2 is less than s1
            sum->elm[k++]=s2->elm[j++];
            
            else//row and column both are same
            {
                sum->elm[k]=s1->elm[i++];//copy comple s1 struct elm elements
                sum->elm[k++].x=sum->elm[k].x+s2->elm[j++].x;//add s1 and s2 values
            }
    }
    //remaining elements 
    for(;i<s1->num;i++)
        sum->elm[k++]=s1->elm[i];

    for(;j<s2->num;j++)
        sum->elm[k++]=s2->elm[j];

    sum->num=k;
    return sum;
    
}
int main()
{
    struct sparse s1;
    create(&s1);
    display(s1);
    struct sparse s2;
    create(&s2);
    display(s2);
    struct sparse *sum=add(&s1,&s2);
    printf("\n\n");
    display(*sum);
    
    return 0;
}