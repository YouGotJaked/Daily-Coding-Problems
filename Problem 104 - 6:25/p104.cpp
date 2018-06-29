/*
 * Determine whether a doubly linked list a palindrome.
 * What if it's singly linked?
 * For example, 1 -> 4 -> 3 -> 4 -> 1 returns true while 1 -> 4 returns false.
 */

#include "../include/stdc++.h"

using namespace std;

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

// insert new node at front of list
void insert(Node **head, int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;
    
    if ((*head) != NULL) {
        (*head)->prev = new_node;
    }
    
    (*head) = new_node;
}

// check if list is palindrome
bool isPalindrome(Node *left) {
    if (left == NULL) {
        return true;
    }
    
    // find rightmost node
    Node *right = left;
    while (right->next != NULL) {
        right = right->next;
    }


    while (left != right) {
        if (left->data != right->data) {
            return false;
        }
        
        left = left->next;
        right = right->prev;
    }
    
    return true;
}

void printList(Node *head) {
    Node *current = head;
    
    for (int i = 0; current != NULL; current = current->next) {
        string end = current->next != NULL ? " -> " : "\n";
        cout << current->data << end;
    }
}

int main() {
    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 1);
    
    printList(head);
    
    string output = isPalindrome(head) ? "Palindrome." : "Not palindrome.";
    cout << output << endl;
    
    return 0;
}

