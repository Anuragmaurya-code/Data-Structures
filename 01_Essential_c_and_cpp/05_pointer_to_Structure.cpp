#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct  RECTANGLE
{
    int length;
    int breath;
    /* data */
};
int main()
{
    struct RECTANGLE r={5,5};
    r.length=10;//editing rectangle value
    cout<<"Structure Rectangle in stack and accessed using variable "<<r.length<<" "<<r.breath<<endl;


    //Now Using Pointer
    struct RECTANGLE *p1=&r;
    p1->length=2;//could even be (*p).length=2
    cout<<"Structure Rectangle in stack and accessed using pointer "<<p1->length<<" "<<p1->breath<<endl;


    //Now creating object structure rectangle in heap memory using pointer
    RECTANGLE *p2;//struct can be skipped in c++
    p2=new RECTANGLE;//this is for c++ for c it would be p2=(return datatype *)malloc(size of object need to be created)
                    //here it would be p2=(struct RECTANGLE *)malloc(sizeof(struct RECTANGLE))
    p2->length=14;
    p2->breath=15; 
    cout<<"Structure Rectangle in heap and accessed using pointer "<<p2->length<<" "<<p2->breath<<endl;
}
