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
    //递归写法
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        return _inorderTraversal(root);
    }
    vector<int> _inorderTraversal(TreeNode* root)
    {
        if (!root) {
            return {};
        }
        vector<int> res = _inorderTraversal(root->left);
        res.push_back(root->val);
        vector<int> right = _inorderTraversal(root->right);
        res.insert(end(res), begin(right), end(right));
        return res;
    }
};

class Solution_ {
    //迭代写法
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        TreeNode* cur = root; //指向当前的节点的指针
        stack<TreeNode*> s;
        vector<int> res;

        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();

                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};