#include<iostream>
using namespace std;
class Rectangle
{
    private:
    int length;
    int breadth;
    public:
    Rectangle()//default constructor if no parameter is passed
    {
        length=0;
        breadth=0;
    }
    Rectangle(int l,int b);
    int area();
    int perimeter();//perimeter ,area,rectangle code could even be written inside class like getlength and others have
    void setLength(int l)
    {
        length=l;
    }
    void setbreadth(int b)
    {
        breadth=b;
    }
    int getLength()
    {
        return length;
    }
    int getbreadth()
    {
        return breadth;
    }
    ~Rectangle()
    {
        cout<<"Destructor";
    }
};
Rectangle::Rectangle(int l,int b)
{
    length=l;
    breadth=b;
}
int Rectangle::area()
{
    return length*breadth;
}
int Rectangle::perimeter()
{
    return 2*(length+breadth);
}
int main()
{
    Rectangle r(10,4);
    int a=r.area();
    int p=r.perimeter();
    printf("area = %d perimerter = %d\n",a,p);
    r.setLength(5);
    r.setbreadth(4);
    a=r.area();
    p=r.perimeter();
    printf("area = %d perimerter = %d\n",a,p);
    int l=r.getLength();
    int b=r.getbreadth();
    printf("Length = %d breadth = %d\n",l,b);
    return 0;
}