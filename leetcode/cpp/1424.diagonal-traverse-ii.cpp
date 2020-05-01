#include "oj_header.h"

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        if (nums.empty() || nums[0].empty())
            return {};

        vector<vector<int>> m;

        for (size_t row = 0; row < nums.size(); row++)
        {
            for (size_t col = 0; col < nums[row].size(); col++)
            {
                if (row + col >= m.size())
                {
                    m.push_back({});
                }
                m[row + col].push_back(nums[row][col]);
            }
        }

        vector<int> v{};
        for (auto &line : m)
        {
            v.insert(end(v), rbegin(line), rend(line));
        }

        return v;
    }
};
