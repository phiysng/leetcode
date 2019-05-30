// 55 二叉树的深度

#include "array_util.h"
using namespace std;

int TreeDepth(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    return max(TreeDepth(root->left), TreeDepth(root->right)) + 1;
}

///Ⅱ 平衡二叉树
// see LeetCode 110

bool isBalanced(TreeNode* root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    if (!isBalanced(root->left) || !isBalanced(root->right))
        return false;
    if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
        return false;
    return true;
}

int maxDepth(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// V2
// 只遍历一遍 通过引用将已经遍历过的子树的深度保存下来
// 而非再次遍历子树获得深度
bool isBalanced(TreeNode* pRoot, int* pDepth)
{
    if (pRoot == nullptr) {
        *pDepth = 0;
        return true;
    }

    int left, int right;
    if (isBalanced(pRoot->left, &left) && isBalanced(pRoot->right, &right)) {
        if (abs(left - right) <= 1) {
            *pDepth = max(left, right);
            return true;
        }
    }
    return false;
}
bool isBalanced(TreeNode* root)
{
    int depth = 0;
    return isBalanced(root, &depth);
}
