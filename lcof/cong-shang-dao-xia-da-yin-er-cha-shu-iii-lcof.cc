#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题32 - III. 从上到下打印二叉树 III

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        deque<TreeNode *> levels{root};
        vector<vector<int>> res;
        bool reversed = false;
        while (!levels.empty())
        {
            int _size = levels.size();
            vector<int> oneLevel;
            for (int i = 0; i < _size; ++i)
            {
                auto first = levels.front();
                levels.pop_front();

                oneLevel.push_back(first->val);
                if (first->left)
                {
                    levels.push_back(first->left);
                }
                if (first->right)
                {
                    levels.push_back(first->right);
                }
            }
            if (reversed)
                reverse(begin(oneLevel), end(oneLevel));
            reversed = !reversed;

            res.push_back(move(oneLevel));
        }

        return res;
    }
};
