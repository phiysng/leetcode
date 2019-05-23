/// 面试题21 调整数组顺序使奇数位于偶数前面
#include "./leetcode/cpp/oj_header.h"

class Solution
{
public:
    void ReorderOddEven(int *pData, int length)
    {
        if (pData == nullptr || length == 0)
            return;
        int *pBegin = pData;
        int *pEnd = pData + length - 1;
        while (pBegin < pEnd)
        {
            while (pBegin < pEnd && (*pBegin & 0x1) == 1)
                ++pBegin;
            while (pBegin < pEnd && (*pEnd & 0x1) == 0)
                --pEnd;

            /// 两个指针没有交错
            if (pBegin < pEnd)
            {
                /// swap
                int t = *pBegin;
                *pBegin = *pEnd;
                *pEnd = t;
            }
        }
    }

    /// 通用版本 采用函数回调 (call back function)
    /// bool (*func)(int) 传入一个函数指针，接受 一个 int作为参数，返回一个布尔值
    void Reorder(int *pData, int length, bool (*func)(int))
    {
        if (pData == nullptr || length == 0)
            return;
        int *pBegin = pData;
        int *pEnd = pData + length - 1;
        while (pBegin < pEnd)
        {
            while (pBegin < pEnd && !func(*pBegin))
                ++pBegin;
            while (pBegin < pEnd && func(*pEnd))
                --pEnd;

            /// 两个指针没有交错
            if (pBegin < pEnd)
            {
                /// swap
                int t = *pBegin;
                *pBegin = *pEnd;
                *pEnd = t;
            }
        }
    }

    void ReorderOddEven_generic(int *pData, int length)
    {
        Reorder(pData, length, isEven);
    }

    /// 采用STL vector实现
    void ReorderOddEven_v2(vector<int> arr)
    {
        /// 实际上是一个 Partition 问题
        /// 来自 QuickSort
        int begin = 0, end = arr.size() - 1;
        while (begin < end) //两个指针没有交集的时候
        {
            while (begin < end && (arr[begin] & 0x1))
            {
                begin++;
            }

            while (begin < end && (arr[end] & 0x1) == 0)
            {
                end--;
            }

            if (begin < end)
            {
                swap(arr[begin], arr[end]);
            }
        }
    }
};

bool isEven(int n)
{
    return n & 1;
}
