#include "oj_header.h"

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return {};

        vector<vector<int>> m;

        for (size_t row = 0; row < matrix.size(); row++)
        {
            for (size_t col = 0; col < matrix[row].size(); col++)
            {
                if (row + col >= m.size())
                {
                    m.push_back({});
                }
                m[row + col].push_back(matrix[row][col]);
            }
        }
        bool even = true;

        vector<int> v{};

        for (auto &line : m)
        {
            if (!even)
            {
                v.insert(end(v), begin(line), end(line));
            }
            else
            {
                v.insert(end(v), rbegin(line), rend(line));
            }

            even = !even;
        }

        return v;
    }
};
