/* 
 * Given the root of a binary tree, find the most frequent subtree sum.
 * The subtree sum of a node is the sum of all values under a node, including the node itself.
 *
 * For example, given the following tree:
 *	5
 *     / \
 *    2  -5
 *
 * Return 2 as it occurs twice: once as the left leaf, and once as the sum of 2 + 5 - 5.
 */

#include <stdio.h>
#include <stddef.h>

#define max(x,y) (x > y ? x : y)

typedef struct node {
	int val;
	struct node *left;
	struct node *right;
} Node;

Node *new_node(int val) {
	Node *temp;
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

int subtree_sum_helper(Node *root, int res) {
	// base case
	if (root == NULL) {
		return 0;
	}
	// subtree sum at current node
	int sum = root->val + 
		  subtree_sum_helper(root->left, res) +
		  subtree_sum_helper(root->right, res);
	
	// update result if current subtree sum is greater
	res = max(res, sum);
	return sum;	
}

int subtree_sum(Node *root) {
	// base case
	if (root == NULL) {
		return 0;
	}
	int res = 0;
	subtree_sum_helper(root, res);
	return res;	
}

int main() {
	Node *root = new_node(5);
	root->left = new_node(2);
	root->right = new_node(-5);
	printf("Largest subtree sum: %d\n", subtree_sum(root));
}
