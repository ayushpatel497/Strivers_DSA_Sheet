class Solution {
public:
    int solve(int m, int n){
        vector<int> dp(n + 1, 1);
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                int right = dp[j];
                int down = dp[j - 1];
                dp[j] = right + down;
            }
        }
        return dp[n];        
    }
    int uniquePaths(int m, int n) {
        // Q. Unique Paths
        return solve(m - 1, n - 1);
    }
};