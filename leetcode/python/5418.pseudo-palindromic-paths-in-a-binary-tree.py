# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from util import TreeNode
from typing import List


class Solution:
    def pseudoPalindromicPaths(self, root: TreeNode) -> int:
        r = [0]

        self.back_track(root, [], r)

        return r[0]

    def back_track(self, root: TreeNode, values: List[int], res: List[int]):

        if self.isLeaf(root):
            values.append(root.val)
            if self.checkValidPseudo(values):
                res[0] += 1
            values.pop()

            return
        values.append(root.val)
        if root.left:
            self.back_track(root.left, values, res)
        if root.right:
            self.back_track(root.right, values, res)

        values.pop()

    def checkValidPseudo(self, values: List[int]):
        m = {}
        for i in range(1, 10):
            m[i] = 0

        for v in values:
            m[v] += 1

        not_even = 0

        for key in m:
            if m[key] % 2 == 1:
                not_even += 1

        if not_even >= 2:
            return False

        return True

    def isLeaf(self, root: TreeNode) -> bool:
        return root and not root.left and not root.right
