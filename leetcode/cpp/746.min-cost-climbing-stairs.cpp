class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int costs = 0;
        if (cost.size() <= 2)
            return min(cost[0], cost[1]);

        int prev = cost[0], curr = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            int t = min(prev, curr);
            t += cost[i];
            prev = curr;
            curr = t;
        }

        return min(curr, prev);
    }
};
