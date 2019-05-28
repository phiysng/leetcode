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
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> q;
        vector<int> res, t;
        q.push(root);
        while (!q.empty())
        {
            size_t size = q.size();
            for (size_t i = 0; i < size - 1; ++i)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            TreeNode *p = q.front();
            q.pop();
            res.push_back(p->val);

            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
            // cout << q.size()<<endl;
        }
        return res;
    }
};
