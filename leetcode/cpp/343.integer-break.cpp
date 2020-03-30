#include "oj_header.h"

class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> map{0, 0, 1, 2, 4};

        if (n <= 4)
            return map[n];

        // use dp solution.
        for (int i = 5; i <= n; ++i)
        {
            int _max = 0;
            for (int k = 1; k < i / 2 + 1; ++k)
            {
                int left = i - k;
                left = left <= 4 ? left : map[i - k];

                int val = left * k;
                _max = max(_max, val);
            }
            map.push_back(_max);
        }

        return map.back();
    }
};
