// 32 从上到下打印二叉树
//相关 LeetCode 102 103 107
#include "array_util.h"
using namespace std;

void PrintFromTopToBottom(TreeNode* root)
{
    if (!root)
        return;

    queue<TreeNode*> q;

    while (!q.empty()) {
        TreeNode* t = q.front();
        q.pop();
        cout << t->val << endl;
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
}

// 分行从上到下打印二叉树
void PrintPerLine(TreeNode* root)
{
    if (!root)
        return;

    queue<TreeNode*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        size_t size = nodes.size();
        for (size_t i = 0; i < size; i++) {
            TreeNode* node = nodes.front();
            nodes.pop();
            printf("%d\t", node->val);
            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
        }
        printf("\n");
    }
}

// 之字形打印二叉树
void Print_v3(TreeNode* root)
{
    if (!root)
        return;
    stack<TreeNode*> levels[2];
    int current = 0;
    int next = 1;

    levels[current].push[root];

    while (!levels[0].empty() && !levels[1].empty()) {
        TreeNode* node = levels[current].top();
        levels[current].pop();

        printf("%d", node->val);

        // 奇数层
        if (current == 0) {
            if (node->left)
                levels[next].push(node->left);
            if (node->right)
                levels[next].push(node->right);
        } else { // 偶数层
            if (node->right)
                levels[next].push(node->right);
            if (node->left)
                levels[next].push(node->left);
        }

        // 如果当前层次遍历完了
        if (levels[current].empty()) {
            printf("\n");
            // swap
            current = 1 - current;
            next = 1 - next;
        }
    }
}
