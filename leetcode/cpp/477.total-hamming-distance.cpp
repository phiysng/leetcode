#include "oj_header.h"

class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
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

        return std::accumulate(begin(bits),end(bits),0,[=](int bit){
            return bit * (_size - bit);
        });
    }
};
