/// 面试题10 斐波那契数列

class Solution {
public:
    int Fibonacci(int n)
    {
        vector<int> res{ 0, 1, 1 };
        res.resize(n + 1);
        for (int i = 3; i < n + 1; ++i) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};
