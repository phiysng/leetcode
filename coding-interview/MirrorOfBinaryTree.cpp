/// 27 二叉树的镜像

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode* pRoot)
    {
        if (!pRoot)
            return;

        /// 叶子节点的优化 不写也是正确的，只是会多一层叶左右子节点的swap
        if (!pRoot->left && !pRoot->right) //leaf node
            return;

        swap(pRoot->left, pRoot->right);
        if (pRoot->left) {
            Mirror(pRoot->left);
        }
        if (pRoot->right) {
            Mirror(pRoot->right);
        }
    }
};
