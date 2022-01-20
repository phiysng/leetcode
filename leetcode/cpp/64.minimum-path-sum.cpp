#include "oj_header.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if (grid.size() == 0)
            return 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                    grid[0][j] += grid[0][j - 1];
                if (j == 0)
                    grid[i][0] += grid[i - 1][0];
                if (i != 0 && j != 0) {
                    grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
                }
            }
        }

        return grid.back().back();
    }
};