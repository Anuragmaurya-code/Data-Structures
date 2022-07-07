#include<iostream>
#include<stdlib.h>
using namespace std;
 
class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
     Node *top;
    public:
        Stack(){top=NULL;}
        void push(int x);
        int pop();
        void Display();
};

void Stack::push(int x)
{
    Node *t=new Node;
    if(t==NULL) 
        cout<<"Stack overflow\n";
    else{
        t->data=x;
        if(top)
        {
            t->next=top;
            top=t;
        }
        else{
            top=t;
            t->next=NULL;
        }
    }
}

int Stack::pop()
{
    int x=-1;
    if(top==NULL)
        cout<<"Stack underflow\n";
    else{
        Node *t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}

void Stack::Display()
{
    
    if(top==NULL)
        cout<<"Stack is Empty\n";
    else{
        Node *t=top;
        while(t)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
    }
}

int main()
{
    Stack st;
    st.pop();
    st.push(5);
    st.push(3);
    st.push(8);
    cout<<"popped "<<st.pop()<<endl;
    st.Display();
    return 0;
}