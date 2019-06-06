// 26 树的子结构

// 约定空树不是任意一个树的子结构，包括另一个空树

struct BinaryTreeNode {
    double val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

// 浮点数相等
bool Equal(double n, double m)
{
    if (n - m > -0.0000001 && n - m < 0.0000001)
        return true;
    else
        return false;
}

// 递归的判断A的某一个子树 是否与 B完全相同
bool DoesTree1HasTree2(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    if (!root2)
        return true;
    if (!root1)
        return false;

    if (!Equal(root1->val, root2->val)) {
        return false;
    }

    return DoesTree1HasTree2(root1->left, root2->left) && DoesTree1HasTree2(root1->right, root2->right);
}

bool HasSubtree(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    bool result = false;

    if (root1 && root2) {
        if (Equal(root1->val, root2->val)) {
            result = DoesTree1HasTree2(root1, root2);
        }
        //不是的情况下 递归左子树
        if (!result) {
            result = HasSubtree(root1->left, root2);
        }
        if (!result) {
            result = HasSubtree(root1->right, root2);
        }
    }

    return result;
}

// 自己实现的牛客网上通过的提交
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == nullptr || pRoot1 == nullptr)
            return false;
        if (pRoot1->val == pRoot2->val) {
            if (_hasSubTree(pRoot1, pRoot2))
                return true;
        }
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
    bool _hasSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == nullptr)
            return true;
        if (pRoot1 == nullptr)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        return _hasSubTree(pRoot1->left, pRoot2->left) && _hasSubTree(pRoot1->right, pRoot2->right);
    }
};
