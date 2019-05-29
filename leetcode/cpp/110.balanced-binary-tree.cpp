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
    bool isBalanced(TreeNode* root)
    {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        if (!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
            return false;
        return true;
    }

    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
