#include<iostream>
#include<stdlib.h>
#include <cstring>
using namespace std;
struct Stack{
    int size;
    int top;
    char *S;
};


void create(Stack *st,char *s)
{
    int x=strlen(s);
    st->size=x;
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

char TopValue(Stack st)
{
    if(st.top==-1)
        return -1;
    else
        return st.S[st.top];
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

int isOperand(char s)
{
    if(s=='*' || s=='/' || s=='+' || s=='-' || s=='^' || s=='(' || s==')')
        return 0;
    else 
        return 1;
}

int out_pre(char s)
{
    if(s=='+' || s=='-')
        return 1;
    else if(s=='*' || s=='/')
        return 3;
    else if(s=='^')
        return 6;
    else if(s=='(')
        return 7;
    else if(s==')')
        return 0;
    return 0;
}

int ins_pre(char s)
{
    if(s=='+' || s=='-')
        return 2;
    else if(s=='*' || s=='/')
        return 4;
    else if(s=='^')
        return 5;
    else if(s=='(')
        return 0;
    return -1;
}

char* ToPost(char *s)
{
    char *postfix;
    int i=0,j=0;
    postfix=new char[strlen(s+2)];
    Stack st;
    create(&st,s);
    push(&st,'#');//because of comaprison of top vale with string 1st value # is pushed
                    //so there wont be any error
    while(s[i]!='\0')
    {
        if(isOperand(s[i]))
           postfix[j++]=s[i++];
        else
        {
            if(out_pre(s[i])>ins_pre(TopValue(st)))//because of this comparison stack cant be expty so # is pushed
                push(&st,s[i++]);
            else if(out_pre(s[i])<ins_pre(TopValue(st)))
            {
                   postfix[j++]=pop(&st);
            }
            else{
                pop(&st);
                i++;
            }
        }
    }
    while(!isEmpty(st))
    {
        postfix[j++]=pop(&st);
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char s[]="((a+b)*c)-d^e^f";
    char *postfix=ToPost(s);
    cout<<postfix;
    return 0;
}