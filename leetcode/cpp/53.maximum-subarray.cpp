#include "oj_header.h"
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int m = nums[0];
        int prev = m;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (prev < 0)
                prev = nums[i];
            else
                prev += nums[i];
            m = max<int>(prev, m);
        }

        return m;
    }
};
