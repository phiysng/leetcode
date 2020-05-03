#include "oj_header.h"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        // 双指针 移动短的指针有可能会更大 而移动更长的指针肯定会更小
        int res = 0;
        while (l < r) {
            int t = (r - l) * min(height[l], height[r]);
            res = max(res, t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};
