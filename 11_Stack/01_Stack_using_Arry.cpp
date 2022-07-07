#include<iostream>
#include<stdlib.h>
using namespace std;
struct Stack{
    int size;
    int top;
    int *S;
};

void create(Stack *st)
{
    cout<<"Enter the size of stack : ";
    cin>>st->size;
    st->top=-1;
    st->S=new int[st->size];
}

void display(Stack st)
{
    if(st.top==-1)
        cout<<"stack is Empty";
    else{
        int i;
        for(i=st.top;i>=0;i--)
        {
            cout<<st.S[i]<<" ";
        }
        cout<<endl;
    }
}

void push(Stack *st,int x)
{
    if(st->size-st->top==1)
    {
        cout<<"stack is overflow\n";
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(Stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        cout<<"Stack is underflow\n";
    }
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(Stack st,int index)
{
    int x=-1;
    if(st.top-index+1<0)
        cout<<"Invalid Index\n";
    else{
        x=st.S[st.top-index+1];
    }
    return x;
}

int StackTop(Stack st)
{
    int x=-1;
    if(st.top!=-1){
        x=st.S[st.top];
    }
    return x;
}

int isEmpty(Stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int isFull(Stack st)
{
    if(st.size-st.top==1)
        return 1;
    else
        return 0;
}
int main()
{
    struct Stack st;
    create(&st);
    display(st);
    return 0;
}