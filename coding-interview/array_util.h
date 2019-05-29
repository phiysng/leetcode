#if !defined(ARRAY_UTIL_C)
#define ARRAY_UTIL_C

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif // ARRAY_UTIL_C
