#include <iostream>
using namespace std;

template<class T>
class Array{
private:
    T * A;
    int size;
    int length;
public:
    Array()
    {
        size=10;
        length=0;
        A=new T[size];

    }
    Array(int size)
    {
        this->size=size;
        length=0;
        A=new T[size];

    }
    void insert(int index,T value){
        if(index>=0 && index<=size){
        for(int i=length;i>index;i--)
        {
            A[i]=A[i-1];
        }
        A[index]=value;
        length++;
        }
    }
    void append(T x){
        if(length<size)
        {
            A[length]=x;
            length++;
        }
    }
    
    void display(){
        for (int i = 0; i < length; i++){
            std::cout<<A[i] << " ";
        }
    }
    int l_search(T value)
    {
        for(int i=0;i<length;i++)
        {
            if(A[i]==value)
            {
                return i;
            }
        }
        return -1;
    }
    void deletion(int index)
    {
        if(index>=0 && index<=length)
        {
            for(int i=index;i<length-1;i++)
            {
                A[i]=A[i+1];
            }
            length--;
            std::cout<<"deleted index "<<index<<" element in array"<<std::endl;
        }    
    }
    T Sum()
    {
        T sum=0;
        for(int i=0;i<length;i++)
            sum=sum+A[i];
        return sum;
    }

    Array* Union(Array);

    ~Array()
    {
        delete []A;
    }
    
};
template<class T>
Array<T>* Array<T>::Union(Array<T> arr2)
{
    Array* arr3=new Array[10];
    int i=0,j=0,k=0,m=0;
    for(i=0;i<length;i++,k++)
        arr3->A[k]=A[i];
    for(i=0;i<arr2.length;i++)
        {
            int l=0,j=0;
            while(j<length)
            {
                if(arr2.A[i]==A[j])
                {
                    l=1;
                    break;
                }
                j++;

            }
            if(l==0)
                arr3->A[k++]=arr2.A[i];
        }
        arr3->length=k;
        arr3->size=100;
        return arr3;
    }



int main() {
    int i,sz;
    int x;
    cout<<"Enter size of array ";
    cin>>sz;
    Array<int> arr(sz);
    int ch;
    do{
        cout<<"\nMenu\n";
        cout<<"1.Append\n";
        cout<<"2.Insert\n";
        cout<<"3.Search\n";
        cout<<"4.Sum\n";
        cout<<"5.Display\n";
        cout<<"6.Delete\n";
        cout<<"7.Exit\n";

        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter element to appended\n";
                cin>>x;
                arr.append(x);
                break;

            case 2:
                cout<<"Enter element to be inserted\n";
                cin>>x;
                cout<<"Enter position of element\n";
                cin>>i;
                arr.insert(i,x);
                break;

            case 3:
                cout<<"Enter element to be searched\n";
                cin>>x;
                i=arr.l_search(x);
                if(i==-1)
                    cout<<"Element not found\n";
                else
                    cout<<"Element found at "<<i<<" position ";
                break;

            case 4:
                cout<<"Sum of array elements is "<<arr.Sum();
                break;

            case 5:
                arr.display();
                break;

            case 6:
                cout<<"Enter index at which elements will be deleted\n";
                cin>>i;
                arr.deletion(i);
                break;

        }
    }while(ch<7);

    Array<int> a2(10);
    a2.append(4);
    a2.append(5);
    a2.append(6);
    Array<int> *a3=arr.Union(a2);
    a3->display();

    return 0;
}