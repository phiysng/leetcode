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
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        auto x = getLeafValue(root1);
        auto y = getLeafValue(root2);
        if (x.size() != y.size())
            return false;
        if (x.size() == 0)
            return true;
        return std::equal(x.begin(), x.end(), y.begin(), y.end());
    }
    bool isLeaf(TreeNode* root)
    {
        if (!root)
            return false;
        return !root->left && !root->right;
    }
    vector<int> getLeafValue(TreeNode* root)
    {
        if (!root)
            return {};
        stack<TreeNode*> s;
        vector<int> v;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (isLeaf(t))
                v.push_back(t->val);
            if (t->right)
                s.push(t->right);
            if (t->left)
                s.push(t->left);
        }
        return v;
    }
};