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
    self->size++;
    self->Q = (int*)malloc(self->size * sizeof(int));
    self->front = self->rear = 0;
}

void Queue_enqueue(Queue* self, int x) {
    if((self->rear + 1) % self->size == self->front)
        printf("Queue is full\n");
    else{
        self->rear = (self->rear + 1) % self->size;
        self->Q[self->rear] = x;
    }
}

int Queue_dequeue(Queue* self) {
    int x = -1;
    if(self->front == self->rear)
        printf("Queue is full\n");
    else{
        self->front = (self->front + 1) % self->size;
        x = self->Q[self->front];
    }
    return x;
}

void Queue_display(Queue* self) {
    int i = self->front + 1;
    do{
        printf("%d ", self->Q[i]);
        i = (i + 1) % self->size;
    } while(i != (self->rear + 1) % self->size);
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
    Queue_enqueue(&q, 67);
    Queue_display(&q);
    return 0;
}
