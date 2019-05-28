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
    bool isCousins(TreeNode *root, int x, int y)
    {
        unordered_set<int> set;
        queue<TreeNode *> q;
        if (!root)
            return false;
        q.push(root);
        while (!q.empty())
        {
            size_t size = q.size();
            for (size_t i = 0; i < size; i++)
            {
                TreeNode *p = q.front();
                if (p->left && p->right && (p->left->val == x && p->right->val == y || p->left->val == y && p->right->val == x))
                    return false;
                q.pop();
                set.insert(p->val);
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            if (set.find(x) != set.end() && set.find(y) != set.end())
                return true;
            if (set.find(x) != set.end() || set.find(y) != set.end())
                return false;
        }
        return false;
    }
};
