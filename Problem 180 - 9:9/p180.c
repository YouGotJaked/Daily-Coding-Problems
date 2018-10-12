/*
 * Given a stack of N elements, interleave the first half of the stack with the second half reversed using only one other queue. 
 * This should be done in-place.
 * Recall that you can only push or pop from a stack, and enqueue and dequeue from a queue.
 * For example, if the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3].
 * If the stack is [1, 2, 3, 4], it should become [1, 4, 2, 3].
 * Hint: Try working backwards from the end state.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

void interleave(Stack *stack) {
    Queue *queue = createQueue(stack->capacity);
    int cycles = stack->size - 1;
    while (cycles > 0) {
        for (int i = 0; i < cycles; i++) {
            enqueue(queue, pop(stack));
        }
        while (!isEmptyQueue(queue)) {
            push(stack, dequeue(queue));
        }
        cycles--;
    }
}

int main() {
    Stack* stack = createStack(100);
    for (int i = 1; i <= 5; i++) {
        push(stack, i);
    }
    printStack(stack);
    interleave(stack);
}
