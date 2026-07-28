#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *S;
};

void create(struct Stack *st) {
    printf("Enter the size of stack : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int*)malloc(st->size * sizeof(int));
}

void display(struct Stack st) {
    if(st.top == -1)
        printf("stack is Empty");
    else{
        int i;
        for(i = st.top; i >= 0; i--) {
            printf("%d ", st.S[i]);
        }
        printf("\n");
    }
}

void push(struct Stack *st, int x) {
    if(st->size - st->top == 1) {
        printf("stack is overflow\n");
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st) {
    int x = -1;
    if(st->top == -1) {
        printf("Stack is underflow\n");
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int index) {
    int x = -1;
    if(st.top - index + 1 < 0)
        printf("Invalid Index\n");
    else{
        x = st.S[st.top - index + 1];
    }
    return x;
}

int StackTop(struct Stack st) {
    int x = -1;
    if(st.top != -1){
        x = st.S[st.top];
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

int main() {
    struct Stack st;
    create(&st);
    display(st);
    return 0;
}
