//
// Created by wyshou on 2024/5/13.
//
#include "oj_header.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        correct(root1);
        correct(root2);
        return checkEqual(root1 , root2);
    }

    void correct(TreeNode* root){
        if(root == nullptr){
            return;
        }

        if(root->right != nullptr && root->left == nullptr){
            root->left = root->right;
            root->right = nullptr;
        }
        // keep left < right
        if(root->left != nullptr && root->right != nullptr){
            if(root->left->val > root->right->val){
                swap(root->left,root->right);
            }
        }
        correct(root->left);
        correct(root->right);
    }

    bool checkEqual(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr || root2 == nullptr){
            return root1 == root2;
        }
        if(root1->val != root2->val){
            return false;
        }
        return checkEqual(root1->left , root2->left) && checkEqual(root1->right , root2->right);
    }
};