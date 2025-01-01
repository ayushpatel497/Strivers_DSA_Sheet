class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Q. Best Time to Buy and Sell Stock
        int mini = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > mini){
                maxProfit = max(maxProfit, prices[i] - mini);
            }
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};