#include "oj_header.h"

class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int res = 0;
        vector<int> bits(32);

        for (int val : nums)
        {
            int idx = 0;
            while (val)
            {
                bits[idx] += val & 0x1;
                val >>= 1;
                idx++;
            }
        }

        const int _size = nums.size();

        for (auto &bit : bits)
        {
            res += bit * (_size - bit);
        }

        return res;
    }
};
