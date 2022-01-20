#include "oj_header.h"

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<int> v(m, 1); // 第一行

        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) {
                    continue;
                } else {
                    v[j] += v[j - 1];
                }
            }
        }
        return v.back();
    }
};