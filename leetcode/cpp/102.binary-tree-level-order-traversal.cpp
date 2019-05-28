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
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        while (!q.empty())
        {
            vector<int> t;
            size_t size = q.size();
            for (int i = 0; i < size; ++i)
            {
                t.push_back((q.front())->val);
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                ;
                q.pop();
            }
            res.push_back(t);
        }
        return res;
    }
};
