#include "oj_header.h"

class Solution
{
public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        unordered_map<int, int> map;
        int cnt = 0;
        back_track(root, map, cnt);

        return cnt;
    }

    void back_track(TreeNode *root, unordered_map<int, int> &map, int &cnt)
    {
        map[root->val] += 1;
        if (!root->left && !root->right) // leaf node
        {
            //
            int odd_num = std::count_if(begin(map), end(map), [](const auto &e) {
                return e.second % 2 == 1;
            });

            if (odd_num <= 1)
            {
                cnt++;
            }
        }
        else
        {
            if (root->left)
                back_track(root->left, map, cnt);
            if (root->right)
                back_track(root->right, map, cnt);
        }
        map[root->val] -= 1;
    }
};
