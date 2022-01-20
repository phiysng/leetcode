#include "oj_header.h"

class Solution {
public:
    double myPow(double x, int n)
    {
        int64_t n_ = abs(static_cast<int64_t>(n));
        // x == 0 时怎么计算
        if (n == 0)
            return 1;
        double res = fastPow(x, n_);
        return n > 0 ? res : 1 / res;
    }
    
    // 快速幂运算
    double fastPow(double x, int64_t n)
    {
        if (n == 1)
            return x;
        if (n == 2)
            return x * x;
        double t = fastPow(x, n / 2);
        t *= t;
        if (n % 2 == 1) {
            t *= x;
        }
        return t;
    }
};