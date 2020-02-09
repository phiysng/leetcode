#ifndef OJ_H
#define OJ_H
#include <string>
#include <algorithm>
#include <deque>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};
#endif // OJ_H
