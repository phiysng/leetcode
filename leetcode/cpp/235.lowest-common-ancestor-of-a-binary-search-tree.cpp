/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "oj_header.h"

/**
 * @brief iterative version.
 * 
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        auto curr = root;

        while (1)
        {
            if (p->val < curr->val && q->val < curr->val)
            {
                curr = curr->left;
                continue;
            }

            if (p->val > curr->val && q->val > curr->val)
            {
                curr = curr->right;
                continue;
            }

            return curr;
        }
        return nullptr;
    }
};

/**
 * @brief recursive version.
 * 
 */
class _Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (p->val > root->val && q->val > root->val)
        {

            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};
