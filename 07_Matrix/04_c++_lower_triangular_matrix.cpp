#include<iostream>
using namespace std;
class rMatrix//row major representaion
{
    private:
    int n;
    int *A;
    public:
    rMatrix(int n)//constructor of matrix
    {
        this->n=n;
        A=new int[n];   
    }

    void set(int i,int j,int x);

    int get(int i,int j);

    void Display();

    ~ rMatrix(){//destructor destructs/clear heap memory allocated
        delete []A;

    }

};
void rMatrix::set(int i,int j,int x)// :: scope resolution operator to indicate function belong to class matrix
{
    if(i>=j)
    {
        int t=((i*(i-1)/2)+(j-1));
        A[t]=x;
    }
}
int rMatrix::get(int i,int j)
{
    if(i>=j)
    {
        int t=((i*(i-1)/2)+(j-1));
        return A[t];
    }
    else
        return 0;
}
void rMatrix::Display()
{
    for(int i=1;i<=(n);i++)//here  i is considered as matrix index so is started from 1
    {
        for(int j=1;j<=(n);j++)
        {
            if(i>=j)
            {
                int t=((i*(i-1)/2)+(j-1));
                printf("%d ",A[t]);
            }
            else
            printf("%d ",0);
        }
        printf("\n");
    }
}

class cMatrix//row major representaion
{
    private:
    int n;
    int *A;
    public:
    cMatrix(int n)//constructor of matrix
    {
        this->n=n;
        A=new int[n];   
    }

    void cset(int i,int j,int x);

    int cget(int i,int j);

    void cDisplay();

    ~ cMatrix(){//destructor destructs/clear heap memory allocated
        delete []A;

    }

};
void cMatrix::cset(int i,int j,int x)// :: scope resolution operator to indicate function belong to class matrix
{
    if(i>=j)
    {
        if(i>=j)
        {
            A[n*(j-1)-(j-1)*(j-2)/2+(i-j)]=x;
        }

    }
}
int cMatrix::cget(int i,int j)
{
    if(i>=j)
    {
        return A[n*(j-1)-(j-1)*(j-2)/2+(i-j)];
    }
    else
        return 0;
}
void cMatrix::cDisplay()
{
    for(int i=1;i<=n;i++)//here  i is considered as matrix index so is started from 1
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
            {
                printf("%d ",A[n*(j-1)-(j-1)*(j-2)/2+(i-j)]);
            }
            else
            printf("%d ",0);
        }
        printf("\n");
    }
}
int main()
{
    int num,x;
    //using row major formula
    
    printf("Enter number of elements ");
    scanf("%d",&num);
    class rMatrix m(num);
    printf("Enter the elements ");
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            scanf("%d",&x);
            m.set(i,j,x);
        }
    }
    
    m.Display();
    printf("\n\n");
    int num2;
    //using column major formula
    printf("Enter number of elements ");
    scanf("%d",&num2);
    class cMatrix m2(num2);
    printf("Enter the elements ");
    for(int i=1;i<=num2;i++)
    {
        for(int j=1;j<=num2;j++)
        {
            scanf("%d",&x);
            m2.cset(i,j,x);
        }
    }
    m2.cDisplay();
    
    return 0;
}