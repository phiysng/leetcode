/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        /// 递归的合并二叉树
        if (t1 && t2) {
            TreeNode* p1 = mergeTrees(t1->left, t2->left);
            TreeNode* p2 = mergeTrees(t1->right, t2->right);
            TreeNode* p = new TreeNode(t1->val + t2->val);
            p->left = p1;
            p->right = p2;
            return p;
        } else {
            return t1 ? t1 : t2;
        }
    }
};
