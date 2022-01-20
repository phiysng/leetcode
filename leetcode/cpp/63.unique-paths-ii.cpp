#include "oj_header.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;

        vector<int64_t> v(obstacleGrid[0].size());

        for (int i = 0; i < obstacleGrid.size(); ++i) {
            for (int j = 0; j < obstacleGrid[0].size(); ++j) {
                // [0][0]时 如果grid[0][0] == 1的话 可以直接返回0
                if (i == 0 && j == 0) {
                    if (obstacleGrid[0][0] == 1) {
                        v[0] = 0;
                    } else {
                        v[0] = 1;
                    }
                    continue;
                }
                if (obstacleGrid[i][j] == 1) {
                    v[j] = 0;
                    continue;
                }
                if (i == 0) {
                    if (j > 0 && obstacleGrid[0][j - 1] == 1) {
                        v[j] = 0;
                    } else {
                        v[j] = v[j - 1];
                    }
                    continue;
                }

                if (j == 0) {

                    if (obstacleGrid[i - 1][0] == 1) {
                        v[j] = 0;
                    }
                    continue;
                }

                int t = 0;
                if (obstacleGrid[i][j - 1] == 0) {
                    t += v[j - 1];
                }
                if (obstacleGrid[i - 1][j] == 0) {
                    t += v[j];
                }
                v[j] = t;
            }
        }

        return v.back();
    }
};