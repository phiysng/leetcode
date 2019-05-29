class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
            return {};

        vector<vector<int>> res;
        res.push_back({ 1 });
        if (numRows == 1)
            return res;

        for (int i = 1; i < numRows; ++i) {
            res.push_back({ 1 });
            if (i > 1) {
                for (int j = 0; j < i - 1; ++j) {
                    res[i].push_back(res[i - 1][j] + res[i - 1][j + 1]);
                }
            }
            res[i].push_back(1);
        }
        return res;
    }
};
