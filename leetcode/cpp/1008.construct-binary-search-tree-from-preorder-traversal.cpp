#include "oj_header.h"
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
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 0; i < preorder.size(); i++) {
            TreeNode* t = root;
            insertNode(t, preorder[i]);
        }
        return root;
    }
    void insertNode(TreeNode*& root, int val)
    {
        if (!root)
            return;
        if (root->val > val) {
            if (!root->left)
                root->left = new TreeNode(val);
            else
                insertNode(root->left, val);
        }
        if (root->val < val) {
            if (!root->right)
                root->right = new TreeNode(val);
            else
                insertNode(root->right, val);
        }
    }
};
