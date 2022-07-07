#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct Stack{
    int size;
    int top;
    char *S;
};


void create(Stack *st,char *s)
{
    st->size=strlen(s);
    st->top=-1;
    st->S=new char[st->size];
} 

void push(Stack *st,char x)
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

char pop(Stack *st)
{
    char x=-1;
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

int isBalanced(char *s)
{
    int i;
    struct Stack st;
    create(&st,s);

    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(')
            push(&st,'(');
        else if(s[i]==')')
        {
            if(isEmpty(st))
                return 0;
            pop(&st);
        }
    }
    if(isEmpty(st))
        return 1;
    else
        return 0;

}
int main()
{
    char s[]="((Hello))+(World))";
    cout<<isBalanced(s);

    return 0;
}