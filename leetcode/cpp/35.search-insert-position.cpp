#include "oj_header.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= target) return i;
        }
        return nums.size();
    }
};
