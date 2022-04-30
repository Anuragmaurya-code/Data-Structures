#include<iostream>
#include<stdlib.h>
using namespace std;
struct RECTANGLE
{
    int length;
    int breath;
};
void fun1(struct RECTANGLE r1)
{
    (r1.length)++;
    (r1.breath)++;
}
void fun2(struct RECTANGLE &r1)
{
    (r1.length)++;
    (r1.breath)++;
}
void fun3(struct RECTANGLE *r1)
{
    r1->length++;
    r1->breath++;
}
struct RECTANGLE * fun4()
{
    struct RECTANGLE *r2;
    r2=new RECTANGLE;// or r2=(struct RECTANGLE *)malloc(sizeof(struct RECTANGLE));
    r2->length=1;
    r2->breath=2;
    return r2;

}
int main()
{
    struct RECTANGLE r={10,5};
    cout<<"Before any call "<<r.length<<"  "<<r.breath<<endl;
    fun1(r);
    cout<<"After call by value "<<r.length<<"  "<<r.breath<<endl;
    fun2(r);
    cout<<"After call by referece "<<r.length<<"  "<<r.breath<<endl;
    fun3(&r);
    cout<<"After call by address "<<r.length<<"  "<<r.breath<<endl;

    // creating structure in heap memory and accesing them using function
    struct RECTANGLE *ptr=fun4();
    cout<<"After creating structure in heap memory "<<ptr->length<<" "<< ptr->breath<<endl;// -> is to access struct elements using pointer
    return 0;
}
