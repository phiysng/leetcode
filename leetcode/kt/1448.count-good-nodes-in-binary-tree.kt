class Solution {
    fun goodNodes(root: TreeNode?): Int {
        if (root == null) {
            return 0
        }
        return 1 + goodNodes(root.left, root.`val`) + goodNodes(root.right, root.`val`)
    }

    fun goodNodes(root: TreeNode?, _max: Int): Int {
        if (root == null) return 0
        val isGood = if (root.`val` >= _max) 1 else 0
        val _m = Math.max(_max, root.`val`)
        return isGood + goodNodes(root.left, _m) + goodNodes(root.right, _m)
    }

}
