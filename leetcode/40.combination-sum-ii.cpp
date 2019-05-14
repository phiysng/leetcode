// #include"oj_header.h"
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> t;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, t, res);
        return res;
    }
    void dfs(vector<int> &candidates, int target, int s, vector<int> &t, vector<vector<int>> &res)
    {
        if (target == 0)
        {
            res.push_back(t);
            return;
        }

        for (size_t i = s; i < candidates.size(); ++i)
        {
            if (candidates[i] > target)
                break;
            if (i != s && candidates[i] == candidates[i - 1])
                continue;

            t.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, t, res);
            t.pop_back();
        }
    }
};
