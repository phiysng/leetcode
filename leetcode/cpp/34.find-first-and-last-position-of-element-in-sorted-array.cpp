#include "oj_header.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.size() == 0)
            return { -1, -1 };

        // 两次二分查找

        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[l] != target)
            return { -1, -1 };
        int lres = l;

        r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int rres = l - 1;
        return { lres, rres };
    }
};
