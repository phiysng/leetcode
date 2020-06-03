/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun rob(root: TreeNode?): Int {
        // 直接相连的两个结点不能同时偷
        return _rob(root).first
    }

    // 可以用root时的最大值 与 不可以时的最大值
    fun _rob(root: TreeNode?): Pair<Int, Int> {
        if (root == null) return Pair(0, 0)
        val left = _rob(root.left)
        val right = _rob(root.right)
        
        // left[0] shall ge left[1]
        val m1 = root.`val` + left.second + right.second;
        val m2 = left.first + right.first
        return Pair(Math.max(m1, m2), m2);
    }
}
