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
 
    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
        std::cout<<std::endl;
    }
    void del(int index)
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
    ~Array(){//destructor
        delete[] A;
        cout << "Array destroyed" << endl;
    }
};

int main() {
 
    Array arr(10);
    arr.create();
    arr.display();
    arr.del(3);
    arr.display();

    
    

    return 0;
}