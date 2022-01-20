#include "oj_header.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int carry = 0;
        deque<int> res;
        digits[digits.size() - 1]++;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int t = digits[i];
            t = carry ? t + 1 : t;
            carry = t / 10;
            t = t % 10;
            res.push_front(t);
        }
        if (carry)
            res.push_front(1);
        return vector<int>(res.begin(), res.end());
    }
};