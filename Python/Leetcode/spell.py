"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None

        leftmost = root

        while leftmost:
            dummy = Node()
            tail = dummy
            node = leftmost

            while node:
                if node.left:
                    tail.next = node.left
                    tail = tail.next

                if node.right:
                    tail.next = node.right
                    tail = tail.next

                node = node.next

            leftmost = dummy.next

        return root