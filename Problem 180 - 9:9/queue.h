#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue {
    int front;
    int rear;
    int capacity;
    int size;
    int *arr;
} Queue;

Queue *createQueue(int capacity);

// add an item to the queue
void enqueue(Queue *queue, int item);

// remove an item from the queue
int dequeue(Queue *queue);

// return the front item of the queue
int front(Queue *queue);

// return the rear item of the queue
int rear(Queue *queue);

// returns true if stack is empty, else false
int isEmptyQueue(Queue *queue);

// print contents of queue
void printQueue(Queue *queue);

#endif /* QUEUE_H */
