#ifndef OJ_H
#define OJ_H
#include <string>
#include <algorithm>
#include <deque>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x)
        : val(x), left(nullptr), right(nullptr)
    {
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(NULL) {}
};

#endif // OJ_H
