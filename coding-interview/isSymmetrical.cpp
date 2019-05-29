// 28 对称的二叉树

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical(pRoot, pRoot);
    }
    bool isSymmetrical(TreeNode* pRootLeft, TreeNode* pRootRight)
    {
        if (!pRootLeft && !pRootRight)
            return true;
        if (!pRootLeft || !pRootRight)
            return false;

        if (pRootLeft->val != pRootRight->val)
            return false;

        return isSymmetrical(pRootLeft->left, pRootRight->right) && isSymmetrical(pRootLeft->right, pRootRight->left);
    }
};
