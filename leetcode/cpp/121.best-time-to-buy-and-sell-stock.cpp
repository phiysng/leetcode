class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int t = prices[0];
        int profits = 0;
        for(int i = 1; i < prices.size();++i){
            if(prices[i] > t){
                profits = max(profits,prices[i] - t);
            }
            if(prices[i] < t){
                t = prices[i];
            }
        }
        return profits;
        
    }
};
