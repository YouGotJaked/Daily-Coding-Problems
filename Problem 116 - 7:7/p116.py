#
# Generate a finite, but an arbitrarily large binary tree quickly in O(1).
# That is, generate() should return a tree whose size in unbounded but finite.
#

class Node:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self._left = left
        self._right = right
        
        self._left_eval = False
        self._right_eval = False
    
    # use property to define object at look up
    @property
    def left(self):
        if not self._left_eval:
            if random() < 0.5:
                self._left = Node(0)
        self._left_eval = True
        return self._left
    
    @property
    def right(self):
        if not self._right_eval:
            if random() < 0.5:
                self._right = Node(0)
        self._right_eval = True
        return self._right

def generate():
    return Node(0)

def main():
    print generate()

if __name__ == '__main__':
    main()
