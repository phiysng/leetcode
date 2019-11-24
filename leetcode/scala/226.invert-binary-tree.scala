/**
 * Definition for a binary tree node.
 * class TreeNode(var _value: Int) {
 *   var value: Int = _value
 *   var left: TreeNode = null
 *   var right: TreeNode = null
 * }
 */
object Solution {
    def invertTree(root: TreeNode): TreeNode = {
        if(root == null) return root;
        val left = root.left;
        val right = root.right;
        root.right = invertTree(left)
        root.left = invertTree(right)
        
        root
    }
}
