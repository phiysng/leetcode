// 34 二叉树中和为某一值的路径

#include "array_util.h"
using namespace std;

void FindPath(TreeNode* root, int expectedSum)
{
    if (root == nullptr)
        return;
    vector<int> path;
    int currentSum = 0;

    FindPath(root, expectedSum, path, currentSum);
}

bool isLeaf(TreeNode* node)
{
    assert(node != nullptr);
    return !node->left && !node->right;
}

void FindPath(TreeNode* root, int expectedSum, vector<int>& path, int currentSum)
{
    currentSum += root->val;
    path.push_back(root->val);

    // 到达预期和的叶子节点
    if (isLeaf(root) && currentSum == expectedSum) {
        // 打印路径
        for (int i : path) {
            printf("%d\t", i);
        }
        printf("\n");
    }

    if (root->left)
        FindPath(root->left, expectedSum, path, currentSum);

    if (root->right)
        FindPath(root->right, expectedSum, path, currentSum);

    path.pop_back();
}
