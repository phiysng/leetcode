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
    bool findTarget(TreeNode* root, int k)
    {
        vector<int> v;
        inOrderTraverse(v, root);
        return twoSum(v, k);
    }
    void inOrderTraverse(vector<int>& v, TreeNode* root)
    {
        if (!root)
            return;

        inOrderTraverse(v, root->left);
        v.push_back(root->val);
        inOrderTraverse(v, root->right);
    }

    bool twoSum(vector<int>& v, int target)
    {
        int l = 0, r = v.size() - 1;
        if (v.size() <= 1)
            return false;

        while (l < r) {
            int t = v[l] + v[r];
            if (t == target)
                return true;
            if (t > target)
                --r;
            else
                ++l;
        }
        return false;
    }
};
