#ifndef ARRAY_UTIL_C
#define ARRAY_UTIL_C

#include <algorithm>
#include <assert.h>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

__declspec(dllexport) int Partition(int data[], int length, int start, int end);

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v, ListNode* _next)
        : val(v)
        , next(_next)
    {
    }
}

#endif // ARRAY_UTIL_C
