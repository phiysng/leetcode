class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int64_t> res(amount + 1, INT32_MAX);
        if (coins.size() <= 0)
            return 0;
        res[0] = 0;
        for (int i = 1; i < amount + 1; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i >= coins[j] && res[i - coins[j]] != INT_MAX) {
                    res[i] = min(res[i - coins[j]] + 1, res[i]);
                }
            }
        }
        return res[amount] == INT_MAX ? -1 : res[amount];
    }
};