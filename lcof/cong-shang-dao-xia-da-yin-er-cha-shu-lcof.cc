#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题32 - I. 从上到下打印二叉树

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
    vector<int> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        deque<TreeNode *> levels{root};
        vector<int> res;
        while (!levels.empty())
        {
            int _size = levels.size();
            for (int i = 0; i < _size; ++i)
            {
                auto first = levels.front();
                levels.pop_front();

                res.push_back(first->val);
                if (first->left)
                {
                    levels.push_back(first->left);
                }
                if (first->right)
                {
                    levels.push_back(first->right);
                }
            }
        }

        return res;
    }
};
