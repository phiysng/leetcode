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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        bool is_even = false; //是否是偶数层
        while (!q.empty())
        {
            size_t size = q.size();
            deque<int> level; //单层
            for (size_t i = 0; i < size; ++i)
            {
                TreeNode *t = q.front();
                q.pop();
                if (is_even)
                {
                    level.push_front(t->val);
                }
                else
                    level.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            is_even = !is_even;
            res.push_back(vector<int>(begin(level), end(level)));
        }
        return res;
    }
};
