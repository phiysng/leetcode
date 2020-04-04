#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题40. 最小的k个数

/// \todo not fast enough.
class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (k <= 0)
            return {};
        priority_queue<int, vector<int>, less<int>> pq;

        for (auto i : arr)
        {
            /// have item < k or i < maximun item in pq.
            if (pq.size() < k && pq.top() > i)
            {
                pq.push(i);
            }

            if (pq.size() > k)
            {

                pq.pop();
            }
        }
        vector<int> res;
        res.reserve(pq.size());

        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
