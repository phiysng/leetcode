from util import TreeNode
from typing import List

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        queue = [root]
        res = []
        while queue:
            size_ = len(queue)
            for i in range(size_):
                top = queue[i]
                if top.left:
                    queue.append(top.left)
                if top.right:
                    queue.append(top.right)
            res.append(queue[size_ - 1].val)
            queue = queue[size_:]
        return res
