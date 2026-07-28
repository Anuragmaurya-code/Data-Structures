#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void init_Stack(Stack* self) {
    self->top = NULL;
}

void Stack_push(Stack* self, int x) {
    Node *t = (Node*)malloc(sizeof(Node));
    if(t == NULL) 
        printf("Stack overflow\n");
    else{
        t->data = x;
        if(self->top)
        {
            t->next = self->top;
            self->top = t;
        }
        else{
            self->top = t;
            t->next = NULL;
        }
    }
}

int Stack_pop(Stack* self) {
    int x = -1;
    if(self->top == NULL)
        printf("Stack underflow\n");
    else{
        Node *t = self->top;
        self->top = self->top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Stack_Display(Stack* self) {
    if(self->top == NULL)
        printf("Stack is Empty\n");
    else{
        Node *t = self->top;
        while(t)
        {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

int main() {
    Stack st;
    init_Stack(&st);
    Stack_pop(&st);
    Stack_push(&st, 5);
    Stack_push(&st, 3);
    Stack_push(&st, 8);
    printf("popped %d\n", Stack_pop(&st));
    Stack_Display(&st);
    return 0;
}
