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

// 层次迭代
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

// recursively
class Solution_recursive {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(isLeaf(root)) return 1;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        // careful about one child to be null
        if(left == 0) return right + 1;
        if(right == 0) return left + 1;
        return min(left,right) + 1;
    }
    
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
};
