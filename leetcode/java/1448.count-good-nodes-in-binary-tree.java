class Solution {
    public int goodNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + goodNodes(root.left, root.val) + goodNodes(root.right, root.val);
    }

    public int goodNodes(TreeNode root, int m) {
        if (root == null)
            return 0;
        int isGood = root.val >= m ? 1 : 0;
        m = Math.max(m, root.val);
        return isGood + goodNodes(root.left, m) + goodNodes(root.right, m);
    }
}
