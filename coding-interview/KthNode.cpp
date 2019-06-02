// 54 二叉搜索树的第k大节点

#include "array_util.h"
using namespace std;

TreeNode* KthNode(TreeNode* root, int k)
{
    if (!root || k <= 0)
        return nullptr;

    return KthNodeCore(root, k);
}

TreeNode* KthNodeCore(TreeNode* root, int& k)
{
    /// 在这里只要一个子树/父节点时 k==1就将此节点返回

    TreeNode* target = nullptr;

    //中序遍历遍历二叉树

    if (root->left) {
        target = KthNodeCore(root->left, k);
    }

    // 只有在这里才会一次获得递增的序列并且操作k
    if (!target) {
        if (k == 1)
            target = root;

        // 遍历过一个节点，需要的数量减一
        --k;
    }

    // 如果当前函数是最后一个即 此时 k==0 那么不会访问这个if
    // 否则此时将要访问右子树继续遍历递增的节点

    if (!target && root->right) {
        target = KthNodeCore(root->right, k);
    }

    return target;
}
