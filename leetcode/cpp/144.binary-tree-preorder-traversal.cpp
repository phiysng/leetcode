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
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        vector<int> v;
        stack<TreeNode *> _stack;
        _stack.push(root);

        while (!_stack.empty())
        {
            auto item = _stack.top();
            _stack.pop();
            v.push_back(item->val);
            if (item->right)
                _stack.push(item->right);
            if (item->left)
                _stack.push(item->left);
        }

        return v;
    }
};
