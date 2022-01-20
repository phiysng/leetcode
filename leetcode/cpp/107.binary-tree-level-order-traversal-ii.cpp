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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res(0, vector<int>());
        while (!q.empty()) {
            int size = q.size();
            vector<int> t;
            for (int i = 0; i < size; ++i) {
                auto m = q.front();
                q.pop();
                t.push_back(m->val);
                if (m->left)
                    q.push(m->left);
                if (m->right)
                    q.push(m->right);
            }
            res.push_back(t);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
