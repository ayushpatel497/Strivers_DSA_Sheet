//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int recursion(int currIndex, int lastIndex, vector<int> nums){
        if (currIndex == nums.size())
            return 0;
        
        int notTake = 0 + recursion(currIndex + 1, lastIndex, nums);
        int take = 0;
        if (lastIndex == -1 || nums[currIndex] > nums[lastIndex]) {
            take = nums[currIndex] + recursion(currIndex + 1, currIndex, nums);
        }
        
        return max(notTake, take);
    }
    
    int memoization(int currIndex, int lastIndex, vector<int> nums, vector<vector<int>>& dp){
        if (currIndex == nums.size())
            return 0;
        if(dp[currIndex][lastIndex + 1] != -1){
            return dp[currIndex][lastIndex + 1];
        }
        
        int notTake = 0 + memoization(currIndex + 1, lastIndex, nums, dp);
        int take = 0;
        if (lastIndex == -1 || nums[currIndex] > nums[lastIndex]) {
            take = nums[currIndex] + memoization(currIndex + 1, currIndex, nums, dp);
        }
        
        return dp[currIndex][lastIndex + 1] = max(notTake, take);
    }

    int tabulation(vector<int>& nums, int numsSize){
        vector<vector<int>> dp(numsSize + 1, vector<int>(numsSize + 1, 0));

        for(int currIndex = numsSize - 1; currIndex >= 0; --currIndex){
            for(int lastIndex = currIndex - 1; lastIndex >= -1; --lastIndex){
                int notTake = 0 + dp[currIndex + 1][lastIndex + 1];
                int take = 0;
                if (lastIndex == -1 || nums[currIndex] > nums[lastIndex]) {
                    take = nums[currIndex] + dp[currIndex + 1][currIndex + 1];
                }
                dp[currIndex][lastIndex + 1] = max(notTake, take);
            }
        }
        return dp[0][0];
    }

    int spaceOptimized(vector<int>& nums, int numsSize){
        vector<int> curr(numsSize + 1, 0);
        vector<int> next(numsSize + 1, 0);

        for(int currIndex = numsSize - 1; currIndex >= 0; --currIndex){
            for(int lastIndex = currIndex - 1; lastIndex >= -1; --lastIndex){
                int notTake = 0 + next[lastIndex + 1];
                int take = 0;
                if (lastIndex == -1 || nums[currIndex] > nums[lastIndex]) {
                    take = nums[currIndex] + next[currIndex + 1];
                }
                curr[lastIndex + 1] = max(notTake, take);
            }
            next = curr;
        }
        return next[0];
    }
    
  public:
    int maxSumIS(vector<int>& nums) {
        // Q. Max Sum Increasing Subsequence
        // Your code goes here
        int numsSize = nums.size();
        return recursion(0, -1, nums);
        vector<vector<int>> dp(numsSize, vector<int>(numsSize + 1, -1));
        return memoization(0, -1, nums, dp);
        return tabulation(nums, numsSize);
        return spaceOptimized(nums, numsSize);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends