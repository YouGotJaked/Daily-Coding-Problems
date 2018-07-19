/*
 * Given a binary tree, return the level of the tree with minimum sum.
 */

#include "../include/stdc++.h"

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x): data(x), left(NULL), right(NULL) {}
};

int max_sum(Node *root) {
    // base case
    if (root == NULL) {
        return 0;
    }
    
    // initalize
    int result = root->data;
    
    queue<Node*> q;
    q.push(root);
    
    // level order traversal
    while (!q.empty()) {
        int count = q.size();
        int sum = 0;
        while (count--) {
            // dequeue
            Node *temp = q.front();
            q.pop();
            
            sum += temp->data;
            
            // enqueue children
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
        
        // update
        result = max(sum, result);
    }
    
    return result;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);
    
    cout << "Maximum level sum: " << max_sum(root) << endl;
}

