/*
 * Given a linked list and a positive integer k, rotate the list to the right by k places.
 * For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2, it should become 3 -> 5 -> 7 -> 7.
 * Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3, it should become 3 -> 4 -> 5 -> 1 -> 2
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

// rotate linked list to the right by k places
Node *rotate_right(Node **head, int k) {
    // base cases
    if (k == 0 || head == NULL) {
        return *head;
    }
    // initialize current node as head
    Node* current = *head;
    int len = 1;
    // loop until end of list is reached, len will be length of list
    while (current->next != NULL) {
        current = current->next;
        len++;
    }
    
    // change last node's next pointer to previous head
    current->next = *head;
    Node *prev = *head;
    // how many nodes until new head
    int prev_len = len - k % len - 1;
    while (prev_len--) {
        prev = prev->next;
    }
    // initialize new head
    *head = prev->next;
    prev->next = NULL;
    
    return *head;
}

// add node to front of linked list
void push(Node **head, int new_data) {
    // allocate node
    Node* new_node = (Node*) malloc(sizeof(Node));
    // insert new data
    new_node->data = new_data;
    // link old list off new node
    new_node->next = *head;
    // point head to new node
    *head = new_node;
}

// print all elements of list
void print_list(Node *node) {
    for (; node != NULL; node = node->next) {
        printf("%d ", node->data);
        if (node->next != NULL) {
            printf("-> ");
        }
    }
    printf("\n");
}

int main() {
    Node *head1 = NULL, *head2 = NULL;
    // fill first list
    push(&head1, 5);
    push(&head1, 3);
    push(&head1, 7);
    push(&head1, 7);
    // fill second list
    push(&head2, 5);
    push(&head2, 4);
    push(&head2, 3);
    push(&head2, 2);
    push(&head2, 1);
    // rotate first list
    print_list(head1);
    print_list(rotate_right(&head1, 2));
    // rotate second list
    print_list(head2);
    print_list(rotate_right(&head2, 3));
}
