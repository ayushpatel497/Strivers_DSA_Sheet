//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isPalindrome(int i, int j, string& s)
    {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int recursion(int i, int n, string s){
        if(i == n){
            return 0;
        }
        int minCost = INT_MAX;
        for(int j = i; j < n; ++j){
            if(isPalindrome(i, j, s)){
                int cost = 1 + recursion(j + 1, n, s);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }
    int memoization(int i, int n, string s, vector<int>& dp){
        if(i == n){
            return 0;
        }
        if (dp[i] != -1)
            return dp[i];
            
        int minCost = INT_MAX;
        for(int j = i; j < n; ++j){
            if(isPalindrome(i, j, s)){
                int cost = 1 + memoization(j + 1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
  public:
    int palindromicPartition(string &s) {
        // Q. Palindromic Partitioning
        // code here
        int n = s.length();
        return recursion(0, n, s) - 1;
        vector<int> dp(n, -1);
        return memoization(0, n, s, dp) - 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends