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
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty()) {
            size_t size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* t = q.front();
                q.pop();
                if (isLeaf(t))
                    return cnt + 1;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            ++cnt;
        }
        return cnt;
    }
    bool isLeaf(TreeNode* root)
    {
        // assert(root != nullptr);
        return !root->left && !root->right;
    }
};