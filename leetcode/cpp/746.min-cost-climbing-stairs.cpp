class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> v(cost.size() + 1);
        v[0] = cost[0];
        v[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i)
        {
            v[i] = min(v[i - 2] + cost[i], v[i - 1] + cost[i]);
        }
        return min(v[cost.size() - 1], v[cost.size() - 2]);
    }
};
