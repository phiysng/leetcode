/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public boolean isValidBST(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        traverse(root,list);

        for (int i = 1; i < list.size(); i++) {
            if(list.get(i) <= list.get(i-1)){
                return false;
            }
        }
        return true;
    }

    private static void traverse(TreeNode root, List<Integer> res) {
        if (root == null) {
            return;
        }

        if (isLeaf(root)) {
            res.add(root.val);
            return;
        }

        traverse(root.left, res);
        res.add(root.val);
        traverse(root.right, res);
    }

    private static boolean isLeaf(TreeNode root) {
        return root != null && root.left == null && root.right == null;
    }
}
