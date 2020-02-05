#include "oj_header.h"

/**
 * @brief 递归版本 DFS 
 * 
 */
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> v;
        backtrace(0, nums.size(), v, nums);

        return v;
    }

    void backtrace(int first, int n, vector<vector<int>> &res, vector<int> &t)
    {
        if (n == first)
        {
            res.push_back(t);
            return;
        }

        for (int i = first; i < n; ++i)
        {
            swap(t[first], t[i]);
            backtrace(first + 1, n, res, t);

            swap(t[first], t[i]);
        }
    }
};

/**
 * @brief 
 * 
 * @brief 某种意义上使用广度优先搜索
 * 初始: 123
 * 第一次循环: + 213 321
 * 第二次循环: + 132 231 312
 *
 */
class _Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res{nums};
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            // 每一轮得到交换一次后的结果
            auto _size = res.size();
            for (int k = 0; k < _size; ++k)
            {
                auto v = res[k];

                for (int j = i + 1; j < nums.size(); ++j)
                {
                    swap(v[i], v[j]);
                    res.push_back(v);
                    swap(v[i], v[j]);
                }
            }
        }
        return res;
    }
};
