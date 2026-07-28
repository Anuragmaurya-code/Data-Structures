#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int size;
    int top;
    long int *S;
} Stack;

static void createStack(Stack *st) {
    printf("Enter the size of stack : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (long int*)malloc(st->size * sizeof(long int));
}

static void push(Stack *st, long int x) {
    if(st->size - st->top == 1) {
        printf("stack is overflow\n");
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

static long int pop(Stack *st) {
    long int x = -1;
    if(st->top == -1) {
        printf("Stack is underflow\n");
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

static long int StackTop(Stack st) {
    long int x = -1;
    if(st.top != -1){
        x = st.S[st.top];
    }
    return x;
}

static int isEmptyStack(Stack st) {
    if(st.top == -1)
        return 1;
    else
        return 0;
}

static int isFullStack(Stack st) {
    if(st.size - st.top == 1)
        return 1;
    else
        return 0;
}

#endif
