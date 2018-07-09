/*
 * Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s.
 * A subtree of s is a tree consisting of a node in s and all of this node's descendants.
 * The tree s could also be considered as a subtree of itself.
 */

class Node {
    int data;
    Node left, right, next;
    
    Node (int data) {
        this.data = data;
        this.left = this.right = this.next = null;
    }
}


class BinaryTree {
    Node root;
    
    boolean equals(Node r1, Node r2) {
        // base cases
        if (r1 == null & r2 == null) {
            return true;
        } else if (r1 == null || r2 == null) {
            return false;
        }
        
        return (r1.data == r2.data &&
                equals(r1.left, r2.left) &&
                equals(r1.right, r2.right));
    }
    
    boolean isSubtree(Node r1, Node r2) {
        if (r1 == null) {
            return true;
        } else if (r2 == null) {
            return false;
        } else if (equals(r1,r2)) {
            return true;
        } else {
            return isSubtree(r1.left, r2) || isSubtree(r1.right, r2);
        }
    }
    
}

public class p115 {
    public static void main(String[] args) {
        BinaryTree s = new BinaryTree();
        BinaryTree t = new BinaryTree();
        
        /* Binary Tree s:
         *
         *         26
         *        /  \
         *       10   3
         *      /  \   \
         *     4    6   3
         *      \
         *      30
         *
         */
        
        s.root = new Node(26);
        s.root.right = new Node(3);
        s.root.right.right = new Node(3);
        s.root.left = new Node(10);
        s.root.left.left = new Node(4);
        s.root.left.left.right = new Node(30);
        s.root.left.right = new Node(6);
        
        /* Binary tree t:
         *
         *      10
         *     /  \
         *    4    6
         *     \
         *     30
         *
         */
        
        t.root = new Node(10);
        t.root.right = new Node(6);
        t.root.left = new Node(4);
        t.root.left.right = new Node(30);
        
        String output = 
        
    }
}
