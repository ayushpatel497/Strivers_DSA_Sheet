class Solution {
public:
    int recursion(string text1, string text2, int index1, int index2){
        if(index1 == text1.length() || index2 == text2.length()){
            return 0;
        }
        if(text1[index1] == text2[index2]){
            return 1 + recursion(text1, text2, index1 + 1, index2 + 1);
        }
        else{
            return max(recursion(text1, text2, index1 + 1, index2), recursion(text1, text2, index1, index2 + 1));
        }
    }

    int memoization(string text1, string text2, int index1, int index2, vector<vector<int>>& dp){
        if(index1 == text1.length() || index2 == text2.length()){
            return 0;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        if(text1[index1] == text2[index2]){
            return dp[index1][index2] =  1 + memoization(text1, text2, index1 + 1, index2 + 1, dp);
        }
        else{
            return dp[index1][index2] = max(memoization(text1, text2, index1 + 1, index2, dp), memoization(text1, text2, index1, index2 + 1, dp));
        }
    }

    int tabulation(string text1, string text2, int t1Size, int t2Size){
        vector<vector<int>> dp(t1Size + 1, vector<int>(t2Size + 1, 0));
        for(int index1 = t1Size - 1; index1 >= 0; --index1){
            for(int index2 = t2Size - 1; index2 >= 0; --index2){
                if(text1[index1] == text2[index2]){
                    dp[index1][index2] =  1 + dp[index1 + 1][index2 + 1];
                }
                else{
                    dp[index1][index2] = max(dp[index1 + 1][index2], dp[index1][index2 + 1]);
                }
            }
        }
        return dp[0][0];
    }

    int spaceOptimized(string text1, string text2, int t1Size, int t2Size){
        vector<int> curr(t2Size + 1, 0);
        vector<int> next(t2Size + 1, 0);
        for(int index1 = t1Size - 1; index1 >= 0; --index1){
            for(int index2 = t2Size - 1; index2 >= 0; --index2){
                if(text1[index1] == text2[index2]){
                    curr[index2] =  1 + next[index2 + 1];
                }
                else{
                    curr[index2] = max(next[index2], curr[index2 + 1]);
                }
            }
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // Q. Longest Common Subsequence
        int t1Size = text1.size();
        int t2Size = text2.size();
        return recursion(text1, text2, 0, 0);
        vector<vector<int>> dp(t1Size, vector<int>(t2Size, -1));
        return memoization(text1, text2, 0, 0, dp);
        return tabulation(text1, text2, t1Size, t2Size);
        return spaceOptimized(text1, text2, t1Size, t2Size);
    }
};