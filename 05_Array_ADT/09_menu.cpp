#include <iostream>
using namespace std;

class Array{
public:
    int* A;
    int size;
    int length;



    void append(int x){
        if(length<size)
        {
            A[length]=x;
            length++;
        }
    }
    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
    }
    int l_search(int value)
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
    void insert(int index,int value){
        if(index>=0 && index<=size){
            for(int i=length;i>index;i--)
            {
                A[i]=A[i-1];
            }
            A[index]=value;
            length++;
        }
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
    int Sum()
    {
        int sum=0;
        for(int i=0;i<length;i++)
            sum=sum+A[i];
        return sum;
    }

};

int main() {
    Array arr;
    int i,x;
    cout<<"Enter size of array ";
    cin>>arr.size;
    arr.A=new int[arr.size];
    arr.length=0;
    int ch;
    do{
        cout<<"\nMenu\n";
        cout<<"\n1.Append\n";
        cout<<"\n2.Insert\n";
        cout<<"\n3.Search\n";
        cout<<"\n4.Sum\n";
        cout<<"\n5.Display\n";
        cout<<"\n6.Delete\n";
        cout<<"\n7.Exit\n";

        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter element to appended\n";
                cin>>x;
                arr.append(x);
                break;

            case 2:
                cout<<"\nEnter element to be inserted\n";
                cin>>x;
                cout<<"\nEnter position of element\n";
                cin>>i;
                arr.insert(i,x);
                break;

            case 3:
                cout<<"\nEnter element to be searched\n";
                cin>>x;
                i=arr.l_search(x);
                if(i==-1)
                    cout<<"\nElement not found\n";
                else
                    cout<<"\nElement found at "<<i<<" position ";
                break;

            case 4:
                cout<<"Sum of array elements is "<<arr.Sum();
                break;

            case 5:
                arr.display();
                break;

            case 6:
                cout<<"\nEnter index at which elements will be deleted\n";
                cin>>i;
                arr.deletion(i);
                break;
            default:
                cout<<"\nEnter valid number\n";

        }
    }while(ch<7);




    //insert delete search sum display exit

    return 0;
}