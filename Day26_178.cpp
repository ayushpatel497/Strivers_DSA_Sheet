class Solution {
    int recursion(vector<int>& coins, int amount){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        int minimum = INT_MAX;
        for(int coin = 0; coin < coins.size(); ++ coin){
            int answer = recursion(coins, amount - coins[coin]);
            if(answer != INT_MAX){
                minimum = min(minimum, 1 + answer);
            }
        }
        return minimum;
    }

    int memoization(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int minimum = INT_MAX;
        for(int coin = 0; coin < coins.size(); ++ coin){
            int answer = memoization(coins, amount - coins[coin], dp);
            if(answer != INT_MAX){
                minimum = min(minimum, 1 + answer);
            }
        }
        return dp[amount] = minimum;
    }

    int tabulation(vector<int>& coins, int target){
        vector<int> dp(target + 1, INT_MAX);
        dp[0] = 0;
        for(int amount = 1; amount <= target; ++amount){
            for(int coin = 0; coin < coins.size(); ++ coin){
                if(amount - coins[coin] >= 0 && dp[amount - coins[coin]] != INT_MAX){
                    dp[amount] = min(dp[amount], 1 + dp[amount - coins[coin]]);
                }
            }
        }
        return dp[target];
    }


public:
    int coinChange(vector<int>& coins, int amount) {
        // Q. Coin Change
        int answer;
        answer = recursion(coins, amount);
        vector<int> dp(amount + 1, -1);
        answer = memoization(coins, amount, dp);
        answer = tabulation(coins, amount);
        if(answer == INT_MAX){
            return -1;
        }
        return answer;
    }
};