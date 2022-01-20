#include "oj_header.h"

class Solution {
public:
    bool canJump(vector<int>& nums)
    {

        int dis = nums[0];

        for (int i = 1; i < nums.size() && i <= dis; ++i) {
            if (nums[i] + i > dis) {
                dis = nums[i] + i;
            }
        }

        return dis >= nums.size() - 1;
    }
};
