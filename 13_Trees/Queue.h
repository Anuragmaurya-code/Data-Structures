#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

typedef struct Queue {
    int size;
    int front;
    int rear;
    Node **Q;
} Queue;

static void init_Queue(Queue* self) {
    self->size = 100;
    self->Q = (Node**)malloc(self->size * sizeof(Node*));
    self->front = self->rear = -1;
}

static void enqueue(Queue* self, Node *x) {
    if(self->rear == self->size - 1)
        printf("Queue is full\n");
    else {
        ++self->rear;
        self->Q[self->rear] = x;
    }
}

static Node* dequeue(Queue* self) {
    Node *x = NULL;
    if(self->front == self->rear)
        printf("Queue is Empty\n");
    else{
        ++self->front;
        x = self->Q[self->front];
    }
    return x;
}

static int isEmptyQueue(Queue* self) {
    return self->front == self->rear;
}

#endif
