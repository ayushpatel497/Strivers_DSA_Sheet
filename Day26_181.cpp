//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int recursion(int n, int k){
        if(n == 0 || k == 0)
            return 0;
        if(n == 1)
            return k;
        
        int minCost = INT_MAX;
        for(int f = 1; f <= k; ++f)
        {
            int breaked = recursion(n-1, f-1);
            int notBreaked = recursion(n, k-f);
            int cost = max(breaked, notBreaked);
            minCost = min(minCost, cost);
        }
        return 1 + minCost;
    }
    
    int memoization(int n, int k, vector<vector<int>> &dp){
        if(n == 0 || k == 0)
            return 0;
        if(n == 1)
            return k;
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        int minCost = INT_MAX;
        for(int f = 1; f <= k; ++f)
        {
            int breaked = memoization(n-1, f-1, dp);
            int notBreaked = memoization(n, k-f, dp);
            int cost = max(breaked, notBreaked);
            minCost = min(minCost, cost);
        }
        return dp[n][k] = 1 + minCost;
    }
    
    
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        // Q. Egg Dropping Puzzle
        // your code here
        return recursion(n, k);
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return memoization(n, k, dp);
    }
};

//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends