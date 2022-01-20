#include "oj_header.h"

class Solution {
public:
    // O(nlog(k)) 比修改前的版本更快
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i : nums) {
            pq.push(i);

            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
