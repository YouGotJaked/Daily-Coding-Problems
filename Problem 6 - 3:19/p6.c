/*
 * An XOR linked list is a more memory efficient doubly linked list.
 * Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node.
 * Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
 * If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memeory addresses.
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *npx;
} Node;

// returns XOR of node addresses
Node *XOR(Node *a, Node *b) {
    return (Node*) ((uintptr_t)(a) ^ (uintptr_t)(b));
}

void add(Node **head, int data) {
    // allocate memory
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    
    // always XOR of current head and NULL
    new_node->npx = XOR(*head, NULL);
    
    // if list is not empty, npx of current head will be XOR of new node and node next to head
    if (*head != NULL) {
        Node *next = XOR((*head)->npx, NULL);
        (*head)->npx = XOR(new_node, next);
    }
    
    // change head
    *head = new_node;
}

int get(Node *head, int index) {
    Node *current = head;
    Node *prev = NULL;
    Node *next;
    int count = 0;
    
    while (current != NULL) {
        if (count++ == index) {
            return current->data;
        }
        next = XOR(prev, current->npx);
        prev = current;
        current = next;
    }
    assert(0);
}

void print_list(Node *head) {
    Node *current = head;
    Node *prev = NULL;
    Node *next;
    
    while (current != NULL) {
        printf("%d ", current->data);
        next = XOR(prev, current->npx);
        prev = current;
        current = next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 40);
    
    print_list(head);
    
    printf("The node at index 2 contains: %d\n", get(head, 2));
    
    return(0);
}

