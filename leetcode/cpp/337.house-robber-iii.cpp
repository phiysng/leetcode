/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "oj_header.h"

class Solution
{
public:
    int rob(TreeNode *root)
    {
        auto res = _rob(root);

        return res.first;
    }

    pair<int, int> _rob(TreeNode *root)
    {
        if (!root)
        {
            return make_pair(0, 0);
        }

        auto left = _rob(root->left);
        auto right = _rob(root->right);
        // max value that root must not exist.
        int non_root_val = max(left.first, left.second) + max(right.first, right.second);
        // max value that root can in , and ** can not in**.
        int can_have_val = max(root->val + left.second + right.second, non_root_val);

        return make_pair(can_have_val, non_root_val);
    }
};
