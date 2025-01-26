class Solution {
    bool memoization(string s, vector<string>& wordDict, int i, vector<int>& dp){
        if(i < 0){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        for(string word : wordDict){
            int currSize = word.length();
            if(i - currSize + 1 >= 0){
                if (s.substr(i - currSize + 1, currSize) == word && memoization(s, wordDict, i - currSize, dp)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Q Word Break
        vector<int> dp(s.length(), -1);
        return memoization(s, wordDict, s.length() - 1, dp);
    }
};