#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i;
    int j;
    int x;
} Element;

typedef struct {
    int m;
    int n;
    int num;
    Element *elm;
} Sparse;

void init_Sparse(Sparse* self, int m,int n,int num)
{
    self->m=m;
    self->n=n;
    self->num=num;
    self->elm=(Element*)malloc(self->num * sizeof(Element));
}

void destroy_Sparse(Sparse* self)
{
    free(self->elm);
}

Sparse Sparse_add(Sparse* self, Sparse *s)
{
    int i=0,j=0,k=0;//i for referrring elements of array of struct Element pointed by elm  in sparse structure pointed by s1
                    // j for s2 and k for sum
    Sparse sum;
    init_Sparse(&sum, self->m, self->n, self->num + s->num);
    while (i<self->num && j<s->num)
    {
        if(self->elm[i].i<s->elm[j].i)// row of s1 is less than s2
            sum.elm[k++]=self->elm[i++];

        else if(self->elm[i].i>s->elm[j].i)//row of s2 is less than s1
            sum.elm[k++]=s->elm[j++];

        else
        {
            if(self->elm[i].j<s->elm[j].j)//row of s1 and s2 is same but column of s1 is less than s2
                sum.elm[k++]=self->elm[i++];

            else if(self->elm[i].j>s->elm[j].j)//row of s1 and s2 is same but column of s2 is less than s1
            sum.elm[k++]=s->elm[j++];
            
            else//row and column both are same
            {
                sum.elm[k]=self->elm[i];//copy comple s1 struct elm elements
                sum.elm[k++].x=s->elm[j++].x+self->elm[i++].x;//add s1 and s2 values
            }
        }
        
    }
    //remaining elements 
    for(;i<self->num;i++)
        sum.elm[k++]=self->elm[i];

    for(;j<s->num;j++)
        sum.elm[k++]=s->elm[j];

    sum.num=k;
    return sum;
}

void Sparse_read(Sparse* self)
{
    printf("Enter non-zero element\n");
    int i;
    for(i=0;i<self->num;i++)
    {
        scanf("%d %d %d", &self->elm[i].i, &self->elm[i].j, &self->elm[i].x);
    }
}

void Sparse_print(Sparse* self)
{
    int i,j;
    int a;
    a=0;
    printf("\n");
    for(i=0;i<self->m;i++)
    {
        for(j=0;j<self->n;j++)
        {
            if(i==self->elm[a].i && j==self->elm[a].j)
            {
                printf("%d ", self->elm[a++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("---------------------------------------------------------------\n");
}

int main()
{
    Sparse s1;
    init_Sparse(&s1, 3, 3, 3);
    Sparse_read(&s1);
    Sparse_print(&s1);
    
    Sparse s2;
    init_Sparse(&s2, 3, 3, 3);
    Sparse_read(&s2);
    Sparse_print(&s2);
    
    Sparse s3 = Sparse_add(&s1, &s2);
    Sparse_print(&s3);
    
    destroy_Sparse(&s1);
    destroy_Sparse(&s2);
    destroy_Sparse(&s3);
    
    return 0;
}
