// #include"oj_header.h"
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int>candidates{1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> res;
        vector<int> t;
        dfs(candidates, n, k, 0, t, res);
        return res;

    }
    void dfs(vector<int> &candidates,  int target, int k, int idx, vector<int> &t,
             vector<vector<int>> &res)
    {
        if (k == 0  && target == 0) {
            res.push_back(t);
            return;
        }

        for (size_t var = idx; var < candidates.size(); ++var) {
            if (candidates[var] > target) return;
            t.push_back(candidates[var]);
            dfs(candidates,  target - candidates[var], k - 1, var + 1, t, res);
            t.pop_back();
        }
    }
};
