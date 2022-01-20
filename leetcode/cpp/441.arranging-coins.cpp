#include "oj_header.h"

class Solution {
public:
    int arrangeCoins(int n)
    {
        int idx = 1;
        if (n == 0 || n == 1)
            return n;

        for (int i = 1; i < INT_MAX; ++i) {
            n -= i;
            if (n < 0) {
                idx = i - 1;
                break;
            }
        }
        return idx;
    }
};