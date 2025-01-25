class Solution {
    int recursion(int currIndex, int lastIndex, vector<int> nums){
        if (currIndex == nums.size())
            return 0;
        
        int notTake = 0 + recursion(currIndex + 1, lastIndex, nums);
        int take = 0;
        if (lastIndex == -1 || nums[currIndex] > nums[lastIndex]) {
            take = 1 + recursion(currIndex + 1, currIndex, nums);
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
            take = 1 + memoization(currIndex + 1, currIndex, nums, dp);
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
                    take = 1 + dp[currIndex + 1][currIndex + 1];
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
                    take = 1 + next[currIndex + 1];
                }
                curr[lastIndex + 1] = max(notTake, take);
            }
            next = curr;
        }
        return next[0];
    }

    int optimal(vector<int>& nums, int numsSize){
        if(numsSize == 0){
            return 0;
        }

        vector<int> answer;
        answer.push_back(nums[0]);
        for(int index = 1; index < numsSize; ++index){
            if(nums[index] > answer.back()){
                answer.push_back(nums[index]);
            }
            else{
                int justGreatIndex = lower_bound(answer.begin(), answer.end(), nums[index]) - answer.begin();
                answer[justGreatIndex] = nums[index];
            }
        }

        return answer.size();
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        // Q. Longest Increasing Subsequence
        int numsSize = nums.size();
        return recursion(0, -1, nums);
        vector<vector<int>> dp(numsSize, vector<int>(numsSize + 1, -1));
        return memoization(0, -1, nums, dp);
        return tabulation(nums, numsSize);
        return spaceOptimized(nums, numsSize);
        return optimal(nums, numsSize);
    }
};