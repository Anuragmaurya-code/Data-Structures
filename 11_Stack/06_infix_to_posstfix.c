#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int size;
    int top;
    char *S;
};

void create(struct Stack *st, char *s) {
    int x = strlen(s);
    st->size = x;
    st->top = -1;
    st->S = (char*)malloc(st->size * sizeof(char));
}

void push(struct Stack *st, char x) {
    if(st->size - st->top == 1) {
        printf("stack is overflow\n");
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

char TopValue(struct Stack st) {
    if(st.top == -1)
        return -1;
    else
        return st.S[st.top];
}

char pop(struct Stack *st) {
    char x = -1;
    if(st->top == -1) {
        printf("Stack is underflow\n");
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int isEmpty(struct Stack st) {
    if(st.top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack st) {
    if(st.size - st.top == 1)
        return 1;
    else
        return 0;
}

int isOperand(char s) {
    if(s == '*' || s == '/' || s == '+' || s == '-' || s == '^' || s == '(' || s == ')')
        return 0;
    else 
        return 1;
}

int out_pre(char s) {
    if(s == '+' || s == '-')
        return 1;
    else if(s == '*' || s == '/')
        return 3;
    else if(s == '^')
        return 6;
    else if(s == '(')
        return 7;
    else if(s == ')')
        return 0;
    return 0;
}

int ins_pre(char s) {
    if(s == '+' || s == '-')
        return 2;
    else if(s == '*' || s == '/')
        return 4;
    else if(s == '^')
        return 5;
    else if(s == '(')
        return 0;
    return -1;
}

char* ToPost(char *s) {
    char *postfix;
    int i = 0, j = 0;
    postfix = (char*)malloc((strlen(s) + 2) * sizeof(char)); 
    struct Stack st;
    create(&st, s);
    push(&st, '#'); 
    while(s[i] != '\0') {
        if(isOperand(s[i]))
           postfix[j++] = s[i++];
        else {
            if(out_pre(s[i]) > ins_pre(TopValue(st))) 
                push(&st, s[i++]);
            else if(out_pre(s[i]) < ins_pre(TopValue(st))) {
                   postfix[j++] = pop(&st);
            }
            else{
                pop(&st);
                i++;
            }
        }
    }
    while(!isEmpty(st)) {
        char popped = pop(&st);
        if(popped != '#')
            postfix[j++] = popped;
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char s[] = "((a+b)*c)-d^e^f";
    char *postfix = ToPost(s);
    printf("%s\n", postfix);
    free(postfix);
    return 0;
}
