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
    int l_search(int value)
    {
        for(int i=0;i<length;i++)
        {
            if(A[i]==value)
            {
                if(i>0)
                {
                    int t=A[i-1];//Transpose method to improve linear search
                    A[i-1]=A[i];
                    A[i]=t;
                }
                return i;
            }    
        }
        return -1;
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
    cout<<"element found at index "<<arr.l_search(3)<<endl;
    arr.display();
    return 0;
}