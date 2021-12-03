#include<iostream>
using namespace std;
template <class T>
class Rectangle
{
    private:
    T length;
    T breadth;
    public:
    Rectangle(T l,T b);
    T area();
    T perimeter();//perimeter ,area,rectangle code could even be written inside class like getlength and others have
    void setLength(T l)
    {
        length=l;
    }
    void setbreadth(T b)
    {
        breadth=b;
    }
    T getLength()
    {
        return length;
    }
    T getbreadth()
    {
        return breadth;
    }
    ~Rectangle()
    {
        cout<<"Destructor";
    }
};

template <class T>
Rectangle<T>::Rectangle(T l,T b)
{
    length=l;
    breadth=b;
}

template <class T>
T Rectangle<T>::area()
{
    return length*breadth;
}

template <class T>
T Rectangle<T>::perimeter()
{
    return 2*(length+breadth);
}

int main()
{
    cout<<"INTEGER"<<endl;
    Rectangle<int> r(10,4);
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


    cout<<endl<<endl<<"FLOAT"<<endl;
    Rectangle<float> r1(10.0,4.0);
    float a1=r1.area();
    float p1=r1.perimeter();
    printf("area = %f perimerter = %f\n",a1,p1);
    r1.setLength(5.3);
    r1.setbreadth(4.1     );
    a1=r1.area();
    p1=r1.perimeter();
    printf("area = %f perimerter = %f\n",a1,p1);
    float l1=r1.getLength();
    float b1=r1.getbreadth();
    printf("Length = %f breadth = %f\n",l1,b1);
    return 0;
}