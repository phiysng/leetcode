// 7 重建二叉树

///⭐⭐⭐⭐
/// 递归与划分子树比较难理解
/// 根据先序遍历和中序遍历重建二叉树

#include "array_util.h"
using namespace std;

TreeNode* Construct(int* preorder, int* inorder, int length)
{
    if (!preorder || !inorder || length <= 0)
        return nullptr;

    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

TreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    TreeNode* root = new TreeNode(rootValue);

    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        } else {
            throw exception("Invalid input.");
        }
    }

    // 在中序遍历中找到根节点的值
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        ++rootInorder;
    }
    // 遍历找不到
    if (rootInorder == endInorder && *rootInorder != rootValue) {
        throw exception("Invalid input.");
    }

    int lefeLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + lefeLength;

    if (lefeLength > 0) {
        // 存在左子树
        root->left = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }

    if (lefeLength < endPreorder - startPreorder) {
        // 右子树
        root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }

    return root;
}
