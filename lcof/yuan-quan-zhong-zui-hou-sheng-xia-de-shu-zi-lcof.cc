#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题62. 圆圈中最后剩下的数字

class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0; // init position.

        for (int i = 0; i < n - 1; ++i) {
            res = (res + m) % (i + 2);
        }
        return res;
    }
};

/// \brief 模拟解法 TLE

class _Solution {
public:
   int lastRemaining(int n, int m) {
       /// 12345
       /// 3
       /// 3 => 12 ->|<- 45
       /// -> | <- 2 45
       /// 24 -> | <-
       /// -> | <- 4
       /// 4
       vector<int> v;

       for (size_t i = 0; i < n; i++) {
           v.push_back(i);
       }
       int idx = 0;

       for (size_t i = 0; i < n - 1; i++) {
           int _size = v.size();
           int _idx = (idx + m - 1) % _size;
           idx = _idx;
           cout << _idx << endl;
           v.erase(v.begin() + _idx);
       }

       return v.front();
   }
};
