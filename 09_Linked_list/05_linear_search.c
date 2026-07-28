#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *last, *t;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;//addreess is passed and now first is refferd as last

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;//putting address of current node in the next of last node 
        last=t;//assigning current node as last node
    }
}

void Display()
{
    struct Node *p;
    p=first;
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p=p->next;
    }
}

struct Node *Linear_Search(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if(p->data == key)
            return p;
        p=p->next;

    }
    return NULL;
}

struct Node *RLinear_Search(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    else if(p->data == key)
        return p;
    else
        return RLinear_Search(p->next,key);

}

struct Node *ILinear_Search(struct Node *p,int key)
{
    struct Node *q = NULL;
    while(p!=NULL)
    {
        if(p->data == key)
        {
            if(p==first)//  very  important as in case if the first element is same to key there
                        // wont be any value to q 
                return p;
            else
            {
            q->next=p->next;
            p->next=first;
            first=p;
            }
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}


int main()
{
    int A[]={4,5,8,9,7};
    create(A,5);
    struct Node *temp;
    temp=ILinear_Search(first,8);
    if(temp)
        printf("Key founded  %d\n", temp->data);
    else
        printf("Key not found\n");
    Display();
    return 0;
}
