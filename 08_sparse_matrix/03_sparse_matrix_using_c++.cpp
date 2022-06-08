#include<iostream>
using namespace std;
class Element
{
    public:
    int i;
    int j;
    int x;
};
class Sparse
{
    private:
    int m;
    int n;
    int num;
    Element *elm;
    public:
    Sparse(int m,int n,int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        elm=new Element[this->num];
    }
    friend istream & operator >>(istream &is,Sparse &s);// friend is a global function
    friend ostream & operator << (ostream &os,Sparse &s);
    Sparse operator+(Sparse &s);
};
Sparse Sparse::operator+(Sparse &s)
{
    int i=0,j=0,k=0;//i for referrring elements of array of struct Element pointed by elm  in sparse structure pointed by s1
                    // j for s2 and k for sum
    Sparse *sum=new Sparse(m,n,num+s.num);
    sum->elm=new Element[num+s.num];
    while (i<num && j<s.num)
    {
        if(elm[i].i<s.elm[j].i)// row of s1 is less than s2
            sum->elm[k++]=elm[i++];

        else if(elm[i].i>s.elm[j].i)//row of s2 is less than s1
            sum->elm[k++]=s.elm[j++];

        else
        {
            if(elm[i].j<s.elm[j].j)//row of s1 and s2 is same but column of s1 is less than s2
                sum->elm[k++]=elm[i++];

            else if(elm[i].j>s.elm[j].j)//row of s1 and s2 is same but column of s2 is less than s1
            sum->elm[k++]=s.elm[j++];
            
            else//row and column both are same
            {
                sum->elm[k]=elm[i];//copy comple s1 struct elm elements
                sum->elm[k++].x=s.elm[j++].x+elm[i++].x;//add s1 and s2 values
            }
        }
        
    }
    //remaining elements 
    for(;i<num;i++)
        sum->elm[k++]=elm[i];

    for(;j<this->num;j++)
        sum->elm[k++]=s.elm[j];

    sum->num=k;
    return *sum;
}
istream & operator >> (istream &is,Sparse &s)
{
    cout<<"Enter non-zero element\n";
    int i;
    for(i=0;i<s.num;i++)
    {
        cin>>s.elm[i].i>>s.elm[i].j>>s.elm[i].x;
    }
    return is;
}
ostream & operator << (ostream &os,Sparse &s)
{
    int i,j;
    int a;
    a=0;
    cout<<endl;
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.elm[a].i && j==s.elm[a].j)
            {
                cout<<s.elm[a++].x<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<"---------------------------------------------------------------\n";
}
int main()
{
    Sparse s1(3,3,3);
    cin>>s1;
    cout<<s1;
    Sparse s2(3,3,3);
    cin>>s2;
    cout<<s2;
    Sparse s3=s1+s2;
    cout<<s3;
    return 0;
}