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
    int sumRootToLeaf(TreeNode* root)
    {
        if (!root)
            return 0;
        int res = 0, t = 0;
        dfs(root, res, t);
        return res;
    }
    void dfs(TreeNode* root, int& sum, int t)
    {
        t *= 2;
        t += root->val;
        if (!root->left && !root->right) //leaf
        {
            sum += t;
        } else {
            if (root->left)
                dfs(root->left, sum, t);
            if (root->right)
                dfs(root->right, sum, t);
        }
    }
};
