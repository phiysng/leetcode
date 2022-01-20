#include "oj_header.h"

class Solution {
public:
    vector<int> grayCode(int n)
    {
        if (n == 0)
            return { 0 };
        vector<int> res;
        res.push_back(0);

        n = pow(2, n);
        for (int i = 1; i < n; ++i) {
            res.push_back(i ^ (i / 2));
        }

        return res;
    }
};
