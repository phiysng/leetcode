#include "../leetcode/leetcode/cpp/oj_header.h"

class Solution
{
public:
    int numWays(int n)
    {
        vector<int> v{1, 1, 2};

        v.reserve(n + 1);

        for (int i = 3; i <= n; ++i)
        {
            v.push_back((v[i - 1] + v[i - 2]) % 1000000007);
        }

        return v[n];
    }
};