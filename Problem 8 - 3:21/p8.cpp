/*
 * A unival tree (which stands for "universal tree") is a tree where all nodes under it have the same value.
 * Given the root to a binary tree, count the number of unival subtrees.
 * For example, the following tree has 5 unival subtrees:
 *      0
 *     / \
 *    1   0
 *       / \
 *      1   0
 *     / \
 *    1   1
 */

#include "../include/stdc++.h"

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

bool countHelper(Node *root, int &count) {
    // base case
    if (root == NULL) {
        return true;
    }
    
    // count left and right subtrees
    bool left = countHelper(root->left, count);
    bool right = countHelper(root->right, count);
    
    // if any subtree is not unival then the tree cannot be either
    if (left == false || right == false) {
        return false;
    }
    
    // if either subtree is singly but data does not match
    if (root->left && root->data != root->left->data) {
        return false;
    } else if (root->right && root->data != root->right->data) {
        return false;
    }
    
    count++;
    return true;
}

int countUnival(Node *root) {
    int count = 0;
    countHelper(root, count);
    return count;
}

int main() {
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(0);
    root->right->left = new Node(1);
    root->right->right = new Node(0);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(1);
    
    cout << "Unival count is " << countUnival(root) << endl;
    return 0;
}
