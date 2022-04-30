#include<iostream>
using namespace std;
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
        cout<<"Name ";
        cin>>r[i].name;
        cout<<"roll no ";
        cin>>r[i].roll;
        cout<<"Total Marks ";
        cin>>r[i].tot_marks;
        cout<<endl;
    }
    for(i=0;i<3;i++)
    {
        cout<<r[i].name<<" "<< r[i].roll << " "<< r[i].tot_marks << endl;
    }

    return 0;
}