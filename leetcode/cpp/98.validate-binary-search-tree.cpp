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
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> res;
        to_vector(res , root);
        for(int i = 0; i < res.size() -1 ; ++i){
            if(res[i] >= res[i + 1])
                return false;
        }
        return true;
    }
    void to_vector(vector<int> &res , TreeNode* root){
        if(!root) return;
        to_vector(res,root->left);
        res.push_back(root->val);
        to_vector(res,root->right);
    }
};
