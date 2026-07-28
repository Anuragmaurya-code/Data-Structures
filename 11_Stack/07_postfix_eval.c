#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int size;
    int top;
    int *S;
};

void create(struct Stack *st, char *s) {
    int x = strlen(s);
    st->size = x;
    st->top = -1;
    st->S = (int*)malloc(st->size * sizeof(int));
}

void push(struct Stack *st, int x) {
    if(st->size - st->top == 1) {
        printf("stack is overflow\n");
    }
    else {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st) {
    int x = -1;
    if(st->top == -1) {
        printf("Stack is underflow\n");
    }
    else {
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

int eval(char *postfix) {
    struct Stack st;
    create(&st, postfix);
    int i, x1, x2, r;
    for(i = 0; postfix[i] != '\0'; i++) {
        if(isOperand(postfix[i])) {
            push(&st, (postfix[i] - '0'));
        }
        else{
            x2 = pop(&st);
            x1 = pop(&st);
            switch(postfix[i]) {
                case '+':
                   r = x1 + x2;
                   break;
                case '-':
                   r = x1 - x2;
                   break;
                case '*':
                   r = x1 * x2;
                   break;
                case '/':
                   r = x1 / x2;
                   break;
                default:
                    break;
            } 
            push(&st, r);
        }
    }
    return pop(&st);
}

int main() {
    char s[] = "2362/*+";
    int answer = eval(s);
    printf("%d\n", answer);
    return 0;
}
