#ifndef OJ_H
#define OJ_H
#include <cstdint>
#include <string>
#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <math.h>
#include <optional>
#include <queue>
#include <stack>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

// for convenience only! not recommended in real world project.
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

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

#endif // OJ_H
