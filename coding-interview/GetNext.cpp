// 8 二叉树的下一个节点

#include "array_util.h"
using namespace std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if (!pNode)
        return nullptr;

    BinaryTreeNode* pNext = nullptr;

    ///右节点存在的时候，下一个节点在当前节点的右👉子节点
    /// 右节点存在的时候 寻找右节点的最左节点
    if (pNode->right) {
        BinaryTreeNode* pRight = pNode->right;
        while (pRight->left) {
            pRight = pRight->left;
        }

        pNext = pRight;
    } else if (pNode->parent) {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->parent;

        /// 如果当前节点是左子节点，那么下面的循环不会执行 当前的父节点就是下一节点
        /// 否则 需要递归向上寻找父节点
        while (pParent && pCurrent == pParent->right) {
            pCurrent = pParent;
            pParent = pParent->parent;
        }
        pNext = pParent;
    }

    return pNext;
}
