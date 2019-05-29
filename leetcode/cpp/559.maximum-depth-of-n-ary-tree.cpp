/*
// Definition for a Node.
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
*/
class Solution {
public:
    int maxDepth(Node* root)
    {
        if (root == nullptr)
            return 0;
        int max_sub_depth = 0;
        for (Node* i : root->children) {
            max_sub_depth = max(max_sub_depth, maxDepth(i));
        }
        return max_sub_depth + 1;
    }
};
