#
# Print the nodes in a binary tree level-wise.
# For example, the following should print 1, 2, 3, 4, 5.
#     1
#    / \
#   2   3
#      / \
#     4   5
#

class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

# print length of binary tree
def levelOrder(root):
    # base case
    if root is None:
        return

    # create empty queue
    queue = []

    # enqueue root, initialize height
    queue.append(root)

    while (len(queue) > 0):
        # print then remove front of queue
        print queue[0].data,
        node = queue.pop(0)

        # enqueue left child
        if node.left is not None:
            queue.append(node.left)

        # enqueue right child
        if node.right is not None:
            queue.append(node.right)

def main():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.right.left = Node(4)
    root.right.right = Node(5)
    levelOrder(root)

if __name__ == '__main__':
    main()
