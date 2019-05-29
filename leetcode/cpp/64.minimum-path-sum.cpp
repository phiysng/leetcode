class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if (grid.size() == 0)
            return 0;
        if (grid.size() == 1) {
            int sum = 0;
            for (int i : grid[0]) {
                sum += i;
            }
            return sum;
        }

        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size()));

        res[0] = grid[0];

        for (int i = 1; i < grid[0].size(); ++i) {
            res[0][i] = grid[0][i] + res[0][i - 1];
        }
        for (int i = 1; i < grid.size(); ++i) {
            res[i][0] = grid[i][0] + res[i - 1][0];
        }
        for (int i = 1; i < res.size(); ++i) {
            for (int j = 1; j < res[0].size(); ++j) {
                res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
            }
        }
        return res.back().back();
    }
};