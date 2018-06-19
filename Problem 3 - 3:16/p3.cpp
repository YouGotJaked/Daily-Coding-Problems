/*
 * Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
 */

struct Node {
    int key;
    Node *left, *right;
    Node(int x) : key(x), left(NULL), right(NULL) {}
};

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        // data
        inorder(root->right);
    }
}

// encode tree to a string
string serialize(node *root) {
    if (root == )
}

// construct tree from decoded string
Node* serialize(string s) {
    
}

int main() {
    
}
