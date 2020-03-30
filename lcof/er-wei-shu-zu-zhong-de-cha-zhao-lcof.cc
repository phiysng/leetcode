#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题04. 二维数组中的查找

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }

        int m = matrix.size() - 1; //
        int n = 0;

        while (m >= 0 && n < matrix[0].size())
        {

            if (matrix[m][n] == target)
            {
                return true;
            }
            if (matrix[m][n] > target)
            {
                m--;
            }
            else
            {
                n++;
            }
        }

        return false;
    }
};
