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
        
        left_max_v , left_max_no_root_v = self._rob(root.left)
        right_max_v , right_max_no_root_v = self._rob(root.right)
        
        # tuple[0]: max_value you can get from one node.
        # tuple[1]  max_value you can get without this node.
        return (max(left_max_v + right_max_v, root.val + left_max_no_root_v + right_max_no_root_v), left_max_v + right_max_v)
