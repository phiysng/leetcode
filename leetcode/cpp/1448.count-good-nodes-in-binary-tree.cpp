#include "oj_header.h"

class Solution
{
public:
    int goodNodes(TreeNode *root)
    {
        return goodNodes(root, INT_MIN);
    }
    int goodNodes(TreeNode *root, int max_v)
    {
        if (!root)
            return 0;
        int isGood = 0;
        if (root->val >= max_v)
        {
            max_v = root->val;
            isGood++;
        }
        return isGood + goodNodes(root->left, max_v) + goodNodes(root->right, max_v);
    }
};
