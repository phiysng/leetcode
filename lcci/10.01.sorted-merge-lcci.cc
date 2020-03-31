#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题 10.01. 合并排序的数组

class Solution
{
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n)
    {
        int _m = m - 1, _n = n - 1;
        int _size = A.size();
        for (int i = _size - 1; i >= 0; --i)
        {
            if (_m < 0)
            {
                A[i] = B[_n--];
            }
            else
            {
                if (_n < 0)
                {
                    A[i] = A[_m--];
                }
                else
                {
                    if (A[_m] > B[_n])
                    {
                        A[i] = A[_m--];
                    }
                    else
                    {
                        A[i] = B[_n--];
                    }
                }
            }
        }
    }
};
