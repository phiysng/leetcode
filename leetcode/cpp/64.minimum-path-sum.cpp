class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if (grid.size() == 0)
            return 0;
        vector<vector<int>> v(grid.size(), vector<int>(grid[0].size()));

        v[0][0] = grid[0][0];

        for (int i = 1; i < grid[0].size(); ++i) {
            v[0][i] = v[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); ++i) {
            v[i][0] = grid[i][0] + v[i - 1][0];
        }

        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                v[i][j] = min(v[i][j - 1], v[i - 1][j]) + grid[i][j];
            }
        }
        return v.back().back();
    }
};