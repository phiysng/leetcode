# -*- coding=utf-8 -*-
from typing import Optional


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left: Optional[TreeNode] = None
        self.right: Optional[TreeNode] = None
