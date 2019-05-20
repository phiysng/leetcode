// #include"oj_header.h"
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> t;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, t, res);
        return res;
    }
    //sum为当前列中数和
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
            t.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, t, res);
            t.pop_back();
        }
    }
};
