#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题03. 数组中重复的数字

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] >= 0 && nums[i] <= nums.size() - 1 && nums[i] != i && nums[nums[i]] != nums[i])
            {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i)
            {
                return nums[i];
            }
        }
        return nums.size();
    }
};
