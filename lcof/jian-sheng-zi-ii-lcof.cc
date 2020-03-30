#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题14- II. 剪绳子 II

class Solution
{
public:
    int cuttingRope(int n)
    {
        // 2 => 1
        // 3 => 2
        // 4 => 4
        // 5 => 6
        // 6 => 9
        // 7 => 12
        vector<int> map{0, 0, 1, 2, 4};
        if (n <= 4)
            return map[n];

        int64_t res = 1;
        while (n > 4)
        {
            res = (res * 3) % 1000000007;
            n -= 3;
        }

        res = (res * n) % 1000000007;

        return res;
    }
};
