#include "oj_header.h"

class Solution {
public:
    // 求众数
    int majorityElement(vector<int>& nums)
    {
        int n = 1;

        int curr = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == curr) {
                ++n;
            } else {
                --n;
                if (n == -1) {
                    n = 1;
                    curr = nums[i];
                }
            }
        }
        return curr;
    }
};
