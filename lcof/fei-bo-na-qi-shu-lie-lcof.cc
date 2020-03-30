#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题10- I. 斐波那契数列

class Solution
{
public:
    int fib(int n)
    {
        vector<int> v{0, 1};
        if (n <= v.size() - 1)
        {
            return v[n];
        }

        v.reserve(n + 1);

        for (int i = 2; i <= n; ++i)
        {
            v.push_back((v[i - 1] + v[i - 2]) % 1000000007);
        }

        return v.back();
    }
};
