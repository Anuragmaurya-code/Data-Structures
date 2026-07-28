#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void init_Queue(Queue* self) {
    self->front = self->rear = NULL;
}

void Queue_enqueue(Queue* self, int x) {
    Node *t;
    t = (Node*)malloc(sizeof(Node));
    if(t == NULL)
        printf("Queue is full\n");
    else{
        t->data = x;
        t->next = NULL;
        if(self->front == NULL)
            self->front = self->rear = t;
        else{
            self->rear->next = t;
            self->rear = t;
        }
    }
}

int Queue_dequeue(Queue* self) {
    int x = -1;
    Node *t;
    if(self->front == NULL)
        printf("Queue is Empty\n");
    else{
        t = self->front;
        if(self->front->next)
            self->front = self->front->next;
        else
            self->front = NULL;
        x = t->data;
        free(t);
    }
    return x;
}

void Queue_display(Queue* self) {
    Node *i = self->front;
    while(i) {
        printf("%d ", i->data);
        i = i->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    init_Queue(&q);
    Queue_enqueue(&q, 1);
    Queue_enqueue(&q, 2);
    Queue_enqueue(&q, 3);
    Queue_enqueue(&q, 4);
    Queue_enqueue(&q, 5);
    printf("Deleted %d\n", Queue_dequeue(&q));
    Queue_enqueue(&q, 14);
    Queue_enqueue(&q, 15);

    Queue_display(&q);
    return 0;
}
