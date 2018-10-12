#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

Stack *createStack(int capacity) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->size = 0;
    stack->arr = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(Stack *stack, int item) {
    // check if stack is full
    assert(stack->size != stack->capacity);
    stack->arr[++stack->top] = item;
    stack->size++;
    printf("The stack size is now %d\n", stack->size);
}

int pop(Stack *stack) {
    // check if stack is empty
    assert(!isEmptyStack(stack));
    stack->size--;
        printf("The stack size is now %d\n", stack->size);
    return stack->arr[stack->top--];
}

int top(Stack *stack) {
    // check if stack is empty
    assert(!isEmptyStack(stack));
    return stack->arr[stack->top];
}

int isEmptyStack(Stack *stack) {
    return stack->size = 0;
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->size; i++) {
        if (i == 0) {
            printf("[");
        }
        printf(" %d ", stack->arr[i]);
        if (i == stack->size - 1) {
            printf("]\n");
        }
    }
}
