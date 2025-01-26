class Solution {
    int recursion(int start, int end, vector<int>& cuts, int left, int right){
        if(left > right){
            return 0;
        }
        int cost = 1e9;
        for(int index = left; index <= right; ++index){
            int leftCost = recursion(start, cuts[index], cuts, left, index - 1);
            int rightCost = recursion(cuts[index], end, cuts, index + 1, right);
            int currCost = end - start + leftCost + rightCost;
            cost = min(cost, currCost);
        }
        return cost;
    }

    int memoization(int start, int end, vector<int>& cuts, int left, int right, vector<vector<int>>& dp){
        if(left > right){
            return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int cost = 1e9;
        for(int index = left; index <= right; ++index){
            int leftCost = memoization(start, cuts[index], cuts, left, index - 1, dp);
            int rightCost = memoization(cuts[index], end, cuts, index + 1, right, dp);
            int currCost = end - start + leftCost + rightCost;
            cost = min(cost, currCost);
        }
        return dp[left][right] = cost;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        // Q. Minimum Cost to Cut a Stick
        int cutsSize = cuts.size();
        sort(cuts.begin(), cuts.end());
        return recursion(0, n, cuts, 0, cutsSize - 1);
        vector<vector<int>> dp(cutsSize + 1, vector<int>(cutsSize + 1, -1));
        return memoization(0, n, cuts, 0, cutsSize - 1, dp);
    }
};