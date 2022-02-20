#include<iostream>
using namespace std;
class Matrix
{
    private:
    int n;
    int *A;
    public:
    Matrix(int n)//constructor of matrix
    {
        this->n=n;
        A=new int[n];   
    }

    void set(int i,int j,int x);

    int get(int i,int j);

    void Display();

    ~ Matrix(){//destructor destructs/clear heap memory allocated
        delete []A;

    }

};
void Matrix::set(int i,int j,int x)// :: scope resolution operator to indicate function belong to class matrix
{
    if(i==j)
    {
        A[i-1]=x;
    }

}
int Matrix::get(int i,int j)
{
    if(i==j)
        return A[i-1];
    else
        return 0;
}
void Matrix::Display()
{
    for(int i=0;i<(n);i++)
    {
        for(int j=0;j<(n);j++)
        {
            if(i==j)
            cout<<A[i]<<" ";
            else
            cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    Matrix m(3);
    m.set(1,1,4);
    m.set(2,2,5);
    m.set(3,3,6);
    m.Display();
    cout<<m.get(3,3);

    return 0;
}