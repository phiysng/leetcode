class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

from typing import Tuple, Optional


class Solution:
    def rob(self, root: TreeNode) -> int:
        return self._rob(root)[0]
    
    def _rob(self, root: Optional[TreeNode]) -> Tuple:
        if(root == None):
            return (0 , 0)
        
        left , right = self._rob(root.left)
        lleft , rright = self._rob(root.right)
        
        # left: max_value you can get from child node.
        # right max_value you can get without root node.
        return (max(left + lleft, root.val + right + rright), left + lleft)
