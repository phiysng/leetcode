# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
'''
BST的性质:
- 树上不存在重复的结点
- left < root < right

在此题中,我们从根节点开始遍历
如果两个结点都在一边,我们对将左节点作为新的root,右节点同理.
同时 如果说两个结点分别在两棵子树上,或者一个就是当前的根节点,则返回当前的根节点

伪代码:

从根节点开始遍历树
如果节点 ppp 和节点 qqq 都在右子树上，那么以右孩子为根节点继续 1 的操作
如果节点 ppp 和节点 qqq 都在左子树上，那么以左孩子为根节点继续 1 的操作
如果条件 2 和条件 3 都不成立，这就意味着我们已经找到节 ppp 和节点 qqq 的 LCA 

https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian--2/

'''

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        '''
        迭代实现
        '''

        curr = root

        while 1:
            if p.val < curr.val and q.val < curr.val:
                curr = curr.left
                continue

            if p.val > curr.val and q.val > curr.val:
                curr = curr.right
                continue

            return curr

        return None


class _Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        '''
        递归实现
        '''
        if p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor(root.right, p, q)

        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)

        return root
