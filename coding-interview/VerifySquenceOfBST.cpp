// 33 二叉搜索树的后序遍历序列

bool VerifySquenceOfBST(int squence[], int length)
{
    if (squence == nullptr || length <= 0)
        return false;

    int root = squence[length - 1];
    int i = 0;
    //二叉树的左子树
    // 题设假设不存在重复的元素
    for (; i < length; ++i) {
        if (squence[i] > root)
            break;
    }
    int j = i;
    for (; j < length - 1; ++j) {
        if (squence[j] < root) //不符合二叉搜索树的定义
            return false;
    }
    // 下面递归检查
    bool left = true;
    if (i > 0) {
        // i == 0 时 **空树** 肯定是有效的左子树
        // 递归检查从开头开始的长度为 i 的子树
        left = VerifySquenceOfBST(squence, i);
    }
    bool right = true;
    if (i < length - 1) {
        ///如果再大的话就指到当前子树的根节点了
        right = VerifySquenceOfBST(squence + i, length - i - 1);
    }
    return left && right;
}
