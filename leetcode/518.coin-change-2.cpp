class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        //假设数组已排序
        //O(n) 每次遍历增加一种硬币的可能性
        if(amount == 0) return 1;
        if(coins.size() < 1) return 0;
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for(int i : coins){
            for(int j = i ; j < amount + 1 ; ++j){
                dp[j] += dp[j-i];
            }
        }
        
        
        return dp[amount];
    }

};
/*
//DFS 超时
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        //sort
        int res = 0;
        dfs(coins, amount, res, 0);
        return res;
    }
    void dfs(vector<int> &coins, int sum, int &res, int idx)
    {
        if (sum == 0) {
            ++res;
            return;
        }
        for (int i = idx; i < coins.size(); ++i) {
            if(sum - coins[i] >= 0)
                dfs(coins,  sum - coins[i], res, i);
            
        }
    }
};
*/