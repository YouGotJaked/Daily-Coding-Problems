#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "queue.h"

Queue *createQueue(int capacity) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = capacity - 1;
    queue->size = 0;
    queue->arr = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

void enqueue(Queue *queue, int item) {
    // check if queue is full
    assert(queue->size != queue->capacity);
    queue->rear = ++queue->rear % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size++;
    printf("The queue size is now %d\n", queue->size);
}

int dequeue(Queue *queue) {
    // check if queue is empty
    assert(!isEmptyQueue(queue));
    int item = queue->arr[queue->front];
    queue->front = ++queue->front % queue->capacity;
    queue->size--;
    printf("The queue size is now %d\n", queue->size);
    return item;
}

int front(Queue *queue) {
    // check if queue is empty
    assert(!isEmptyQueue(queue));
    return queue->arr[queue->front];
}

int rear(Queue *queue) {
    // check if queue is empty
    assert(!isEmptyQueue(queue));
    return queue->arr[queue->rear];
}

int isEmptyQueue(Queue *queue) {
    return queue->size = 0;
}

void printQueue(Queue *queue) {
    for (int i = queue->front; i < queue->size; i++) {
        if (i == queue->front) {
            printf("[");
        }
        printf(" %d ", queue->arr[i]);
        if (i == queue->size - 1) {
            printf("]\n");
        }
    }
}
