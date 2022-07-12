#include<iostream>
#include<stdlib.h>
#include <cstring>
using namespace std;
struct Stack{
    int size;
    int top;
    int *S;
};


void create(Stack *st,char *s)
{
    int x=strlen(s);
    st->size=x;
    st->top=-1;
    st->S=new int[st->size];
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


int eval(char *postfix)
{
    Stack st;
    create(&st,postfix);
    int i,x1,x2,r;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(&st,(postfix[i]-'0'));
        }
        else{
            x2=pop(&st);
            x1=pop(&st);
            switch(postfix[i])
            {
                case '+':
                   r=x1+x2;
                   break;
                case '-':
                   r=x1-x2;
                   break;
                case '*':
                   r=x1*x2;
                   break;
                case '/':
                   r=x1/x2;
                   break;
                default:
                    break;

            } push(&st,r);
        }
    }
    return pop(&st);
}
int main()
{
    char s[]="2362/*+";
    int answer=eval(s);
    cout<<answer;
    return 0;
}