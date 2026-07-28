#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
} Queue;

void init_Queue(Queue* self) {
    printf("Enter the size of queue\n");
    scanf("%d", &self->size);
    self->Q = (int*)malloc(self->size * sizeof(int));
    self->front = self->rear = -1;
}

void Queue_enqueue(Queue* self, int x) {
    if(self->rear == self->size - 1)
        printf("Queue is full\n");
    else{
        ++self->rear;
        self->Q[self->rear] = x;
    }
}

int Queue_dequeue(Queue* self) {
    int x = -1;
    if(self->front == self->rear)
        printf("Queue is Empty\n");
    else{
        ++self->front;
        x = self->Q[self->front];
    }
    return x;
}

void Queue_display(Queue* self) {
    int i = self->front + 1;
    for(; i <= self->rear; i++)
        printf("%d ", self->Q[i]);
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
    Queue_display(&q);
    return 0;
}
