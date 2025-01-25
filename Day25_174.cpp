class Solution {
    int recursion(string word1, string word2, int index1, int index2){
        if(index1 == word1.length()){
            return word2.length() - index2;
        }
        if(index2 == word2.length()){
            return word1.length() - index1;
        }
        if(word1[index1] == word2[index2]){
            return recursion(word1, word2, index1 + 1, index2 + 1);
        }
        else{
            int insert = 1 + recursion(word1, word2, index1, index2 + 1);
            int del = 1 + recursion(word1, word2, index1 + 1, index2);
            int replace = 1 + recursion(word1, word2, index1 + 1, index2 + 1);
            return min(insert, min(del, replace));
        }
    }

    int memoization(string word1, string word2, int index1, int index2, vector<vector<int>>& dp){
        if(index1 == word1.length()){
            return word2.length() - index2;
        }
        if(index2 == word2.length()){
            return word1.length() - index1;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        if(word1[index1] == word2[index2]){
            return dp[index1][index2] = memoization(word1, word2, index1 + 1, index2 + 1, dp);
        }
        else{
            int insert = 1 + memoization(word1, word2, index1, index2 + 1, dp);
            int del = 1 + memoization(word1, word2, index1 + 1, index2, dp);
            int replace = 1 + memoization(word1, word2, index1 + 1, index2 + 1, dp);
            return dp[index1][index2] = min(insert, min(del, replace));
        }
    }

    int tabulation(string word1, string word2, int w1Size, int w2Size){
        vector<vector<int>> dp(w1Size + 1, vector<int>(w2Size + 1, 0));
        for(int index1 = 0; index1 < w1Size; ++index1){
            dp[index1][w2Size] = w1Size - index1;
        }
        for(int index2 = 0; index2 < w2Size; ++index2){
            dp[w1Size][index2] = w2Size - index2;
        }
        for(int index1 = w1Size - 1; index1 >= 0; --index1){
            for(int index2 = w2Size - 1; index2 >= 0; --index2){
                if(word1[index1] == word2[index2]){
                    dp[index1][index2] = dp[index1 + 1][index2 + 1];
                }
                else{
                    int insert = 1 + dp[index1][index2 + 1];
                    int del = 1 + dp[index1 + 1][index2];
                    int replace = 1 + dp[index1 + 1][index2 + 1];
                    dp[index1][index2] = min(insert, min(del, replace));
                }
            }
        }
        return dp[0][0];  
    }

    int spaceOptimized(string word1, string word2, int w1Size, int w2Size){
        vector<int> curr(w2Size + 1, 0);
        vector<int> next(w2Size + 1, 0);
        for(int index2 = 0; index2 < w2Size; ++index2){
            next[index2] = w2Size - index2;
        }
        for(int index1 = w1Size - 1; index1 >= 0; --index1){
            for(int index2 = w2Size - 1; index2 >= 0; --index2){
                curr[w2Size] = w1Size - index1;// catch from base case
                if(word1[index1] == word2[index2]){
                    curr[index2] = next[index2 + 1];
                }
                else{
                    int insert = 1 + curr[index2 + 1];
                    int del = 1 + next[index2];
                    int replace = 1 + next[index2 + 1];
                    curr[index2] = min(insert, min(del, replace));
                }
            }
            next = curr;
        }
        return next[0];  
    }

public:
    int minDistance(string word1, string word2) {
        // Q. Edit Distance
        int w1Size = word1.length(), w2Size = word2.length();
        if(w1Size == 0){
            return w2Size;
        }
        if(w2Size == 0){
            return w1Size;
        }
        return recursion(word1, word2, 0, 0);
        vector<vector<int>> dp(w1Size, vector<int>(w2Size, -1));
        return memoization(word1, word2, 0, 0, dp);
        return tabulation(word1, word2, w1Size, w2Size);
        return spaceOptimized(word1, word2, w1Size, w2Size);
    }
};