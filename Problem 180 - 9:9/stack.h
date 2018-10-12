#ifndef STACK_H
#define STACK_H

typedef struct stack {
	int top;
	int capacity;
    int size;
	int *arr;
} Stack;

Stack *createStack(int capacity);

// add an item to the stack
void push(Stack *stack, int item);

// remove an item from the stack
int pop(Stack *stack);

// return the top item of the stack
int top(Stack *stack);

// returns true if stack is empty, else false
int isEmptyStack(Stack *stack);

// print contents of stack
void printStack(Stack *stack);

#endif /* STACK_H */
