#include "oj_header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        // 删除超过两个的数
        // 只要维护一个指向当前的不重复的数字的指针/索引就好
        
        if (nums.size() == 0)
            return 0;
        int counts = 1;
        int prev = nums[0];
        int idx = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (prev != nums[i] || (prev == nums[i] && counts <= 1)) {
                nums[idx] = nums[i];
                ++idx;

                if (prev != nums[i]) {
                    counts = 1;
                } else {
                    ++counts;
                }
            } else {

                ++counts;
            }
            prev = nums[i];
        }
        return idx;
    }
};