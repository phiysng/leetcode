#include "oj_header.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int i = 0, j = 0;
        int n = matrix[0].size(), m = matrix.size();

        vector<int> res;

        while (i < m && j < n) {
            if (i + 1 == m) {
                //只剩一行
                for (int k = j; k < n; ++k) {
                    res.push_back(matrix[i][k]);
                    cout << res.back() << endl;
                }
                break;
            }
            if (j + 1 == n) {
                //只剩一列的时候
                for (int k = j; k < m; ++k) {
                    res.push_back(matrix[k][j]);
                    cout << res.back() << endl;
                }
                break;
            }
            //最少两行两列
            for (int k = j; k < n; ++k) {
                res.push_back(matrix[i][k]);
            }

            for (int k = i + 1; k < m; ++k) {
                res.push_back(matrix[k][n - 1]);
            }

            for (int k = n - 2; k >= j; --k) {
                res.push_back(matrix[m - 1][k]);
            }

            for (int k = m - 2; k >= i + 1; --k) {
                res.push_back(matrix[k][j]);
            }
            ++i;
            ++j;
            --m;
            --n;
        }
        return res;
    }
};
