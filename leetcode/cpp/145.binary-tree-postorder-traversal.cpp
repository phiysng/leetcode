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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> stack_;
        if(!root){
            return v;
        }
        stack_.push(root);
        /// l r mid => reversed mid r l(much simpler)
        while(!stack_.empty()){
            auto _v = stack_.top();
            stack_.pop();
            v.push_back(_v->val);
            
            if(_v->left)  {
                stack_.push(_v->left);
            }

            if(_v->right){
            stack_.push(_v->right);
            }
        }

        reverse(begin(v),end(v));

        return v;
    }
};
