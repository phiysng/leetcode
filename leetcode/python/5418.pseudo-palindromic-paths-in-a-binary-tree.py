# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from util import TreeNode
from typing import List
from typing import Dict


class Solution:
    def pseudoPalindromicPaths(self, root: TreeNode) -> int:
        r = [0]
        d = {}
        for i in range(1, 10):
            d[i] = 0

        self.back_track(root, d, r)

        return r[0]

    def back_track(self, root: TreeNode, m: Dict[int, int], res: List[int]):

        if self.isLeaf(root):
            m[root.val] += 1
            if self.checkValidPseudo(m):
                res[0] += 1
            m[root.val] -= 1
            return

        m[root.val] += 1
        if root.left:
            self.back_track(root.left, m, res)
        if root.right:
            self.back_track(root.right, m, res)

        m[root.val] -= 1

    def checkValidPseudo(self, m: Dict[int, int]):

        not_even = 0
        for key in m:
            if m[key] % 2 == 1:
                not_even += 1

        if not_even >= 2:
            return False

        return True

    def isLeaf(self, root: TreeNode) -> bool:
        return root and not root.left and not root.right
