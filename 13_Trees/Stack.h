
struct Stack{
    int size;
    int top;
    long int *S;
};

void create(Stack *st)
{
    cout<<"Enter the size of stack : ";
    cin>>st->size;
    st->top=-1;
    st->S=new long int[st->size];
}



void push(Stack *st,long int x)
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

long int pop(Stack *st)
{
    long int x=-1;
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



long int StackTop(Stack st)
{
    long int x=-1;
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
