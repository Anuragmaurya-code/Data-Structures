#include <iostream>
using namespace std;
 
class Array{
 
private:
    int* A;
    int size;
    int length;
 
public:
    Array(int size){
        this->size = size;
        A = new int [size];
    }
 
    void create(){
        cout << "Enter number of elements: " << flush;
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++){
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }
    void append(int a)
    {
        if(length<size)
        {
            A[length]=a;
            length++;
        }
    }
 
    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
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
 
    ~Array(){//destructor
        delete[] A;
        cout << "Array destroyed" << endl;
    }
};

int main() {
 
    Array arr(10);
    arr.create();
    arr.append(2);
    arr.insert(3,78);
    arr.display();
    

    return 0;
}