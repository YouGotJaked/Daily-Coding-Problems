#
# Given a binary tree, return all paths from the root to leaves.
# For example, given the tree:
#
#       1
#      / \
#     2   3
#        / \
#       4   5
#
# It should return [ [1,2], [1,3,4], [1,3,5] ].

# binary tree node with data, left and right pointer
class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

# print all possible paths
def printAllPaths(root):
    path = []
    printPath(root, path, 0)

# print path from root to leaf
def printPath(root, path, pathLen):
    # base case
    if root is None:
        return

    # add current root's data into list
    if (len(path) > pathLen):
        path[pathLen] = root.data
    else:
        path.append(root.data)

    pathLen = pathLen + 1

    if root.left is None and root.right is None:
        printList(path, pathLen)
    else:
        printPath(root.left, path, pathLen)
        printPath(root.right, path, pathLen)

def printList(ints, len):
    for i in ints[0 : len]:
        print(i, " ", end="")
    print()

def main():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.right.left = Node(4)
    root.right.right = Node(5)

    printAllPaths(root)

if __name__ == '__main__':
    main()
