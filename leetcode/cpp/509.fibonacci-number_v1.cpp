class Solution {
public:
    ///
    /// 没有优化过的递归解法
    ///
    int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }

        return fib(n - 1) + fib( n - 2);
    }
};